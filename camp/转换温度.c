#include <stdio.h>


void mode1(){
    char c1;
    printf("请输入大写字母:");

    c1=getchar();
    if (c1>='A' && c1<='Z'){
        c1=c1+32;
    }
    printf("%c\n",c1);
}

void mode2(){
    float C,F;
    printf("请输入一个华氏温度:");
    scanf("%f",&F);
    C=(5.0/9)*(F-32);
    printf("华氏温度%f 转换为摄氏温度后的结果为: %.2f\n",F,C);
}

int main(){
    int signal = 0;

    while(1){

        printf("------------------------------------------------------------\n");

        printf("模式 1: 华摄氏温度转换\n模式 2: 大写字母改小写\n模式 0: 退出\n");

        // printf("\n");

        printf("------------------------------------------------------------\n");

        printf("请输入程序运行模式:");

        scanf("%d",&signal);
        getchar(); // 吃掉 scanf 后残留的回车

        printf("------------------------------------------------------------\n");
        

        if (signal==0){
            break;
        }

        if (signal==1){
            mode2();

            printf("------------------------------------------------------------\n");

            printf("按回车键继续......\n");

            while (getchar() != '\n');

            getchar();

        }

        if (signal==2){
            mode1();

            printf("------------------------------------------------------------\n");


            printf("按回车键继续......\n");

            while (getchar() != '\n');

            getchar();
            
        }



    }


    return 0;
    
}