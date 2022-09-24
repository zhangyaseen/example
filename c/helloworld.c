// 预处理： gcc -E helloworld.c -o helloworld.i
// 编译： gcc -S helloworld.i -o helloworld.s
// 汇编： gcc -c helloworld.s -o helloworld.o
// 链接： gcc helloworld.o helloworld

#include <stdio.h>

int main(void) {
    printf("hello world\n");
    return 0;
}