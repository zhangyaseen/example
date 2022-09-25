#include <stdio.h>

int main(void) {
    char ch = 0x7f; // 127
    char ci = ch + 2;
    printf("ch: %d, ci: %d\n", ch, ci);

    unsigned char cj = 0x7f;
    unsigned char ck = cj + 2;
    unsigned char cl = cj + ck;
    printf("cj: %d, ck: %d, cl: %d\n", cj, ck, cl);

    return 0;
}