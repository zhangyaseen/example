#include <stdio.h>

int main(void) {
  char arr[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '\n'};
  void *p = NULL;
  p = (void *)&arr;

  *((char *)p + 1) = 'z';
  for (int i = 0; i < 10; ++i) {
    putchar(arr[i]);
  }

  *((int *)p + 1) = 88;
  for (int i = 0; i < 10; ++i) {
    putchar(arr[i]);
  }

  return 0;
}