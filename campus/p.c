#include <stdio.h>



/*----------------*/

int getn();
int printp();
int a();


/*----------------*/


int main()

{
    // getn();

    a();

    // printf ("\n");
    




}


int getn()
{


    int a,b,c;

    while (1)
    {

        printf("Pless Enter Number:");

        scanf("%d",&a);

        printf("%d\n",a);



    }

}

int printp()

{
    int n = 100;
    int *p;   // 定义一个int指针p，用来存放int变量地址

    p = &n;   // ✅把n的地址存入指针p。p现在等于&n（0x1000）
    // *p = &n; ❌错误！*p是取地址里的值，不能把地址赋值给一个数值

    printf("n的值 = %d\n", n);
    printf("n的地址 = %p\n", &n);
    printf("p里面存放的地址 = %p\n", p);
    printf("*p 解引用，p指向地址里的值 = %d\n", *p);

    *p = 200; // 解引用！找到p保存的地址（也就是n的地址），把里面的值改成200
    printf("修改后 n = %d\n", n); // n变成200！
    return 0;


}

int a()

{
    int a,b,sum;

    int *p;

    p=&a;

    printf("%p",p);
    return 0;


}