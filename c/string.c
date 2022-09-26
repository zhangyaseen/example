#include <stdio.h>
#include <string.h>

int main(void) {
  char s[] = "abcd efg";
  printf("s: len: %ld, strlen: %lu, context: %s\n", sizeof(s) / sizeof(char),
         strlen(s), s);

  char s1[] = {'a', 'b', 'c', 'd', ' ', 'e', 'f', 'g', '\0'};
  printf("s1: len: %ld, %s\n", sizeof(s1) / sizeof(char), s1);

  return 0;
}