// gcc -S extern.c -o extern.s

#include <stdio.h>

int main(void) {
    extern int a;
    // a = 10; not allocate memory
    int b = 10;
    
    return 0;
}