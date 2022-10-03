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

int main(void) {
  max(10, 20);

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

  return 0;
}