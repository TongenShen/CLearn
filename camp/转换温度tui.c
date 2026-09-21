#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void print_line(void) {
    printf("\033[1;36m------------------------------------------------------------\n\033[0m");
}

void mode1() {
    char c1;
    printf("请输入大写字母:");
    c1 = getchar();
    while (getchar() != '\n');   // 清掉多余输入
    if (c1 >= 'A' && c1 <= 'Z') {
        c1 = c1 + 32;
    }
    printf("转换结果: %c\n", c1);
}

void mode2() {
    float C, F;
    printf("请输入一个华氏温度:");
    scanf("%f", &F);
    while (getchar() != '\n');   // 清残留
    C = (5.0 / 9) * (F - 32);
    printf("华氏温度 %f 转换为摄氏温度后的结果为: %.2f\n", F, C);
}

int main() {
    int signal = 0;

    while (1) {
        system(CLEAR);

        printf("\033[1;36m============================================================\n\033[0m");
        printf("\033[1;33m                       校园工具菜单\n\033[0m");
        printf("\033[1;36m============================================================\n\033[0m");
        printf("\033[1;33m模式 1: 华氏温度转摄氏温度\n\033[0m");
        printf("\033[1;33m模式 2: 大写字母改小写\n\033[0m");
        printf("\033[1;31m模式 0: 退出\n\033[0m");
        print_line();

        printf("\033[1;32m请输入程序运行模式: \033[0m");
        scanf("%d", &signal);
        while (getchar() != '\n');   // 清残留

        if (signal == 0) {
            printf("\033[1;31m已退出，再见！\n\033[0m");
            break;
        }

        if (signal == 1) {
            print_line();
            mode2();
            printf("\n按回车键继续......\n");
            while (getchar() != '\n');
            getchar();
        }

        if (signal == 2) {
            print_line();
            mode1();
            printf("\n按回车键继续......\n");
            while (getchar() != '\n');
            getchar();
        }

        if (signal != 0 && signal != 1 && signal != 2) {
            printf("\033[1;31m输入无效，请输入 0、1 或 2\033[0m\n");
            printf("\n按回车键继续......\n");
            while (getchar() != '\n');
            getchar();
        }
    }

    return 0;
}
