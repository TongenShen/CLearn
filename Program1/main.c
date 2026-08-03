#include <stdio.h>

int main() {
    while (1)
    {
        int n;

        printf("请输入指数 n：");
        scanf("%d", &n);

        if (n < 0) {
            printf("暂不支持负数指数\n");
            return 1;
        }

        long long result = 1;
        for (int i = 0; i < n; i++) {
            result *= 16;
        }

        printf("16 的 %d 次方 = %lld\n", n, result);
    }
    return 0;
}
