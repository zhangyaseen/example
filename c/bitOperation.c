#include <stdio.h>

int main(void) {
    int a = 1;
    int b = 2;
    
    //  001 & 010 = 000， 同时为1，才为1
    int c = a & b;

    //  001 | 010 = 011  有1为1
    int d = a | b;

    // 001 ^ 010 = 011 相同为0， 不同为1
    int e = a ^ b;

    printf("c: %d, d: %d, e: %d\n", c, d, e);

    return 0;
}