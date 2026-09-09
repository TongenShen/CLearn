#define PAI 3.14
#include <stdio.h>
#include<stdlib.h>

int main()

{   

    printf("这个是一个小玩具\n 你可以按 exit 退出\n");

    char text;

    fgets(text, sizeof(text), stdin);        // 读一整行（包括空格）

    printf ("%c",text);

    exit(0);

    while (1)
    {


        float r1=3,r2=4,s1,s2;

        s1=r1*r1*PAI;

        s2=r2*r2*PAI;

        printf("S1=%f\nS2=%.2f\n",s1,s2); //%.2f 是取 2 位小数

    }


    return 0;

}
