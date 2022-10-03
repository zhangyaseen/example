#include <stdio.h>
#include <stdlib.h>

void c_malloc(void) {
  char *p = (char *)malloc(sizeof(char) * 5);
  for (int i = 0; i < 5; ++i) {
    putchar('[');
    putchar(p[i]);
    putchar(']');
  }
  putchar('\n');

  free(p);
  p = NULL;
}

void c_calloc(void) {
  char *p = calloc(5, sizeof(char));
  for (int i = 0; i < 5; ++i) {
    putchar('[');
    putchar(p[i]);
    putchar(']');
  }
  putchar('\n');

  free(p);
  p = NULL;
}

void c_realloc(void) {
  char *p = calloc(5, sizeof(char));
  for (int i = 0; i < 5; ++i) {
    p[i] = 'a' + i;
  }

  char *q = realloc(p, 10 * sizeof(char));
  printf("p point:%p, q point: %p\n", p, q);

  for (int i = 0; i < 10; ++i) {
    putchar('[');
    putchar(q[i]);
    putchar(']');
  }
  putchar('\n');

  free(q);
  q = NULL;
}

int main(void) {
  printf("malloc:\n");
  c_malloc();

  printf("calloc:\n");
  c_calloc();

  printf("realloc:\n");
  c_realloc();

  return 0;
}