// gcc -S extern.c -o extern.s

#include <stdio.h>

int c;

int main(void) {
  extern int a;
  // a = 10; not allocate memory
  int b = 10;

  extern int c;
  c = 30;

  //  printf("extern base: %p, %p, %p\n", &a, &b, &c); error
  printf("extern base: %p, %p\n", &b, &c);

  return 0;
}