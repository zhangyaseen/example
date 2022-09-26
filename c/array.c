#include <stdio.h>

void basic(void) {
  int a[3];
  printf("a not init value : %d, %d, %d\n", a[0], a[1], a[2]);
  printf("a address: a: %p, a[0]: %p, a[1]: %p, a[2]: %p\n", &a, &a[0], &a[1],
         &a[2]);
  int b[3] = {};
  printf("b init value : %d, %d, %d\n", b[0], b[1], b[2]);
  printf("b address: b: %p, b[0]: %p, b[1]: %p, b[2]: %p\n", &b, &b[0], &b[1],
         &b[2]);

  printf("step: a next : %p, a[0] next: %p, b next: %p, b[0] next: %p\n",
         &a + 1, &a[0] + 1, &b + 1, &b[0] + 1);
}

void point_array(void) {
  int *p[3];
  int a = 10;
  int b = 20;
  int c = 30;
  p[0] = &a;
  p[1] = &b;
  p[2] = &c;
}

int main(void) {
  basic();

  point_array();

  return 0;
}