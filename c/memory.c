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

void memory_static_local_global(void) {
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
}

void memory_stack() {
  int a = 10;
  int b = 20;
  int c = 30;
  printf("a : %p\t, b: %p\t, c:%p\n", &a, &b, &c);

  int num = 0xaabbccdd;
  unsigned char *p = (unsigned char *)&num;
  printf("num: %x\t, %x\t, %x\t, %x\n", *p, *(p + 1), *(p + 2), *(p + 3));
}

int main(void) {
  printf("memory static local global:\n");
  memory_static_local_global();

  printf("memroy stack:\n");
  memory_stack();

  return 0;
}