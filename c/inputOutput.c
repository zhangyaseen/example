#include <stdio.h>

void output(void) {
    printf("number : %d\n", 100);
    putchar('a');
    printf("\noutput end....\n");
}

void input_getchar(void) {
    printf("begin getchar:\n");
    char ch1 = getchar();
    printf("getchar ch1: %c\n", ch1);

    getchar(); // 读取输入的回车

    printf("begin getchar:\n");
    char ch2 = getchar();
    printf("getchar ch2: %c\n", ch2);

    getchar(); // 读取输入的回车
    printf("end getchar.....\n");
}

void input_scanf(void) {
    printf("begin scanf char:\n");
    char ch1;
    scanf("%c", &ch1);
    printf("scanf ch1: %c\n", ch1);

    printf("begin scanf int:\n");
    int a1;
    scanf("%d", &a1);
    printf("scanf a1: %d\n", a1);
}

int main(void) {
    output();

    input_getchar();
    input_scanf();

    return 0;
}