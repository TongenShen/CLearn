#include <stdio.h>
int main()

{

    int a,b;
    signed short int c;
    short d=100 ;
    a=d-20;
    b=a+d;
    c=a+b+d;
    d = d-a-c-b;
    printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);
    return 0;

}