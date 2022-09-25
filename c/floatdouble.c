
#include <stdio.h>

int main(void) {
    float a = 3.14f;
    float b = 2.18f;
    float c = 1.16f;

    double o = 1.01;
    double p = 2.02;
    double q = 3.06;

    printf("float : %p, %p, %p, %ld\n", &a, &b, &c, sizeof(a));
    printf("double : %p, %p, %p, %ld\n", &o, &p, &q, sizeof(o));

    return 0;
}