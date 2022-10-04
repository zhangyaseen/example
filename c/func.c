#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int, int);
int max(int x, int y);

int max(int x, int y) { return x > y ? x : y; }

void alloc_space(char **p) {
  *p = (char *)malloc(sizeof(char) * 100);
  strcpy(*p, "hello world");
}

void free_space(char **p) {
  if (!p) {
    return;
  }

  if (*p) {
    free(*p);
    *p = NULL;
  }
}

void alloc_value(char *p) {
  printf("alloc value begin : %p, %p\n", &p, p);
  p = (char *)malloc(sizeof(char) * 100);
  printf("alloc value end: %p, %p\n", &p, p);
  strcpy(p, "hello world");
}

void alloc_param(void) {
  char *p = NULL;
  alloc_space(&p);
  printf("alloc memory string: %s\n", p);
  free_space(&p);

  char *x = (char *)malloc(sizeof(char) * 20);
  printf("x %p =  %s\n", x, x);
  char *q = x;
  alloc_value(q);
  printf("q: %p = %s\n", q, q);
  printf("x %p =  %s\n", x, x);
}

typedef int(FUNC_TYPE)(int, int);
int my_func(int a, int b) {
  printf("my func: %d, %d\n", a, b);
}

void func_type(void) {
  FUNC_TYPE *p1 = my_func;
  p1(10, 20);

  FUNC_TYPE p2;
  // p2(10,20); error;
}

typedef int(*FUNC_POINT)(int, int);
void func_point(void) {
  FUNC_POINT p1 = my_func;
  p1(10, 20);

  int (*f)(int, int) = my_func;
  (*f)(10, 20);
}

void func_01(int a) {
  printf("func 01\n");
}
void func_02(int a) {
  printf("func 02\n");
}
void func_03(int a) {
  printf("func 03\n");
}

void func_array(void) {
#if 0
    void (*my_func_array[])(int) {func_01, func_02, func_03};
#else 
    void (*my_func_array[3])(int);
    my_func_array[0] = func_01;
    my_func_array[1] = func_02;
    my_func_array[2] = func_03;
#endif

  for (int i = 0; i < 3; i++) {
    my_func_array[i](10+i);
    (*my_func_array[i])(10+i);
  }

}

int plus(int a, int b) {
  return a+b;
}

void call_back(int(*my_cal)(int, int), int a, int b) {
  int ret = my_cal(a, b);
  printf("ret = %d\n", ret);
}

int main(void) {
  max(10, 20);

  alloc_param();

  func_type();
  func_point();

  func_array();

  call_back(plus, 10, 20);

  return 0;
}