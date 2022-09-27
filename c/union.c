#include <stdio.h>

typedef union Data {
  unsigned char a;
  unsigned int b;
  unsigned short c;
} Data;

int main(void) {
  Data d;

  printf("data element point: %p, %p, %p\n", &d.a, &d.b, &d.c);
  printf("Data size: %ld\n", sizeof(d));

  d.b = 0x44332211;
  printf("b 0x44332211: %x, %x, %x\n", d.a, d.b, d.c);

  d.a = 0x00;
  printf("a 0x00 %x, %x, %x\n", d.a, d.b, d.c);

  return 0;
}
