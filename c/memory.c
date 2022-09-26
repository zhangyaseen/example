#include <stdio.h>

int x = 0;

void static_add() {
  static int a = 0;
  a++;
  printf("a: %d, addr:%p\n", a, &a);
}

void global_add() {
  x++;
  printf("x: %d, addr:%p\n", x, &x);
}

void local_add(int b) {
  b++;
  printf("b: %d, addr:%p\n", b, &b);
}

int main(void) {
  int m = 10;
  printf("m: %d, addr:%p\n", m, &m);
  local_add(m);

  static_add();
  static_add();
  static_add();

  global_add();
  global_add();
  global_add();

  local_add(10);

  int n = 10;
  printf("n: %d, addr:%p\n", n, &n);
  local_add(n);

  return 0;
}