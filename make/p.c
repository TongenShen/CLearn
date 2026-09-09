#include <stdio.h>
int main ()

{
    int one = 100;

    int *ip;

    ip = &one;

    printf("one %p\n",&one);

    printf("ip %p\n",ip);

    printf("valve %d\n",*ip);

    return 0;

}