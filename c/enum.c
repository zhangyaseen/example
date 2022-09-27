#include <stdio.h>

enum Weekly { sum = 1, mon, tue, ed, thur, fri, sta };

int main(void) {
  printf("Weekly: %d, %d, %d, %d, %d, %d, %d", sum, mon, tue, ed, thur, fri,
         sta);

  enum Weekly a, b, c;
  a = sum;
  b = ed;
  c = sta;
  printf("value: %d, %d, %d\n", a, b, c);
  printf("sizeof enum: %ld\n", sizeof(a));

  return 0;
}