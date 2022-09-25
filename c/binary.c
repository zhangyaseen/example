#include <stdio.h>

int main(void) {
    int a = 3;
    int b = -3;
    int c = a + b;

    // 0...011
    printf("a: %d, %x\n", a, a);
    // 1...011 原码
    // 1111100 反码
    // 1111101 补码
    printf("b: %d, %x\n", b, b);
    // 0...000
    printf("c: %d, %x\n", c, c);
}