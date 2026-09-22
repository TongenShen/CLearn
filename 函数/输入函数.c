/*
本章主要讲解 C语言常见的输入函数,以及对比.

核心区分：读单个字符 / 读一整行 / 格式化解析
头文件基本都是 <stdio.h>

1. fgets()    —— 读取一整行（优先推荐，最安全）
2. scanf()    —— 格式化读取，最常用
3. getchar()  —— 读取单个字符
4. gets()     —— 已废弃，绝对不要用（C11 标准已删除该函数）
5. sscanf()   —— 不是键盘输入，是从已有字符串中解析数据

场景快速选择表：
    读取一整行，允许带空格（名字、句子）   → fgets
    读取整数、小数，简单输入不带空格       → scanf
    只读取单个按键字符                     → getchar
    先读一整行，再拆分里面多个数字         → fgets + sscanf

工程最佳实践：
    读一行用户输入，一律优先 fgets，再配合 sscanf 解析数字；
    只有极简小程序才直接用 scanf 读数字。

典型坑：
    1. scanf 读完数字，缓冲区剩 \n，下一个 fgets 直接读到空行
    2. fgets 会带回 \n，做字符串比较时记得删掉
    3. scanf("%s") 遇到空格截断，不能读句子

补充：在 Windows 控制台运行若中文乱码，先执行 chcp 65001 切换 UTF-8 代码页
*/

//引入头文件
#include <stdio.h>
#include <string.h>   // strcspn() 和 strlen()

void test_fgets()
{
    // fgets：读一整行，允许带空格，有长度限制不会缓冲区溢出
    char buf[128];

    // 演示1：读带空格的整行
    printf("【fgets】请输入一句话（可带空格）：");
    fgets(buf, sizeof(buf), stdin);
    printf("你输入的是：%s", buf);   // \n 被保留，所以输出自带换行

    // 演示2：\n 会保留在缓冲区里，做字符串比较前要删掉
    buf[strcspn(buf, "\n")] = '\0';  // 把第一个 \n 替换成 \0
    printf("删掉换行后：%s（长度 = %zu）\n", buf, strlen(buf));

    // 演示3：fgets + sscanf 组合，安全读一行多个数字
    int a, b;
    printf("请输入两个整数（用空格分隔）：");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d %d", &a, &b);
    printf("解析结果：a = %d, b = %d\n", a, b);
}

void test_scanf()
{
    // scanf：按格式符解析，自动跳过空格、回车、Tab
    int age;
    printf("【scanf】请输入年龄（整数）：");
    scanf("%d", &age);
    printf("age = %d\n", age);

    // 坑1：读完数字后，回车\n残留在缓冲区，fgets 不会等你输入，直接读剩下的内容
    char buf[64];
    printf("注意：回车还留在缓冲区，现在 fgets 读下一行：\n");
    fgets(buf, sizeof(buf), stdin);
    printf("fgets 读到的字符串长度 = %zu（只输了数字的话，这里就是残留的\\n）\n", strlen(buf));

    // 坑3：%s 遇到空格就停止，不能读带空格的句子
    char word[64];
    int ch;
    printf("请输入两个单词（如 hello world）：");
    scanf("%63s", word);   // %63s 限制最大宽度，避免缓冲区溢出（裸 %s 不安全）
    printf("scanf(\"%%s\") 只读到了：%s\n", word);
    printf("剩下的内容还在缓冲区，现在 getchar() 会读到残留的字符：");
    ch = getchar();
    printf("'%c'（ASCII = %d）\n", ch, ch);

    // 清空缓冲区残留，避免影响后面的函数
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void test_getchar()
{
    // getchar：一次读 1 字节，返回 int（存字符或 EOF），空格回车都能读到
    int ch, tmp;

    // 经典用法1：单字符按键判断（y/n）
    printf("【getchar】是否继续？(y/n)：");
    ch = getchar();
    while ((tmp = getchar()) != '\n' && tmp != EOF);   // 清掉这一行的剩余内容
    printf("你按的是：%c\n", ch);

    // 经典用法2：读取单个数字字符，转成数字
    printf("请输入一个数字字符（0~9）：");
    ch = getchar();
    while ((tmp = getchar()) != '\n' && tmp != EOF);
    printf("字符 %c 转成数字 = %d\n", ch, ch - '0');

    // 补充：getchar 读到文件末尾返回 EOF（-1），
    // 在 Linux/macOS 按 Ctrl+D、Windows 按 Ctrl+Z 可以触发
}

/*
gets() —— 彻底废弃，绝对不要用！
    gets(buf) 没有长度限制，极易缓冲区溢出。
    C11 标准已直接删除该函数，现代编译器编译会直接报错。
    网上旧代码看到 gets，一律替换成 fgets(buf, sizeof(buf), stdin)。
*/

void test_sscanf()
{
    // sscanf：不是键盘输入！是从已有的字符串里解析数据
    // 最佳组合：fgets 安全读一行 → sscanf 解析多个数字
    char buf[64];
    int a, b;

    printf("【fgets + sscanf】请输入两个整数（用空格分隔）：");
    fgets(buf, sizeof(buf), stdin);    // 先安全读整行
    sscanf(buf, "%d %d", &a, &b);      // 再从字符串解析
    printf("解析成功：a = %d, b = %d\n", a, b);

    // 也可以直接从已经存在的字符串中解析
    char str[] = "12 34 56";
    int x, y, z;
    sscanf(str, "%d %d %d", &x, &y, &z);
    printf("从字符串 \"%s\" 解析出：%d, %d, %d\n", str, x, y, z);
}

//主函数,只用来执行子函数内容,所有解释以及执行代码都在对应的子函数
int main()
{
    test_fgets();
    printf("\n----------------------------------------\n\n");
    test_scanf();
    printf("\n----------------------------------------\n\n");
    test_getchar();
    printf("\n----------------------------------------\n\n");
    test_sscanf();

    return 0;
}
