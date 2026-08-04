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
        // 循环 n 次，每次把 result 乘以 16，从而算出 16 的 n 次方
        // int i = 0;   -> 定义计数器 i，从 0 开始（只在循环内有效）
        // i < n;       -> 每轮开始前判断：i 小于 n 就继续循环，否则结束
        // i++          -> 每轮结束后 i 加 1
        for (int i = 0; i < n; i++) {
            result *= 16; // 等价于 result = result * 16;
        }
        // 例如 n = 3：i = 0,1,2 共执行 3 次，result = 1*16*16*16 = 4096

        printf("16 的 %d 次方 = %lld\n", n, result);
    }
    return 0;
}
