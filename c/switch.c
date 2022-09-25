#include <stdio.h>

int main(void) {
    char c = '1';

    switch (c)
    {
    case '1':
        printf("1 ok\n");
        break;
    case '2':
        printf("2 ok\n");
        break;
    default:
        printf("default ok\n");
    }

    return 0;
}