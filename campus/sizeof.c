#include <stdio.h>

/* 函数声明（原型）：分号结尾，没有函数体 */
void pn(void);

int main()

{
    pn();

    int n,i;
    int factorial = 1 , sum = 0 ;
    float factorial_float=1.0,sum_float=0.0;
    double factorial_double=1.0,sum_double=0.0;
    printf("Pless enter a int number:");
    scanf("%d",&n);

    pn();

    for (i=1;i<=n;++i)
    {
        factorial *= i;
        sum += factorial;
    }

    /* sizeof 计算占用字节数，size_t 用 %zu 打印 */
    printf("int 占用 %zu 字节\n", sizeof(int));
    printf("float 占用 %zu 字节\n", sizeof(float));
    printf("double 占用 %zu 字节\n", sizeof(double));
    printf("%d 的阶乘 = %d，阶乘和 = %d\n", n, factorial, sum);

    pn();   /* 调用在 main 后面定义的函数 */

    return 0;
}

void pn(void)

{



    int nnn=0;
    while (nnn<10)
    {
        nnn+=1;
    printf("-----");
    }
    printf("\n");



}
