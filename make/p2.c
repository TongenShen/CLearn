#include<stdio.h>
void change(int *a)
{
    *a = 999;
}
int main()
{
    int x = 10;
    int *p = &x; // 把地址存起来
    change(p);
}