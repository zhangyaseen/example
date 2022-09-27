#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
  char *name;
  int age;
} Person;

int main(void) {
  Person a;
  a.age = 100;
  a.name = (char *)malloc(sizeof(char) * 10);
  strncpy(a.name, "llllll", 6);

  Person b = a;

  Person *p = (Person *)malloc(sizeof(Person));
  p->name = (char *)malloc(sizeof(char) * 10);
  strncpy(p->name, "abcdef", 6);
  p->age = 18;

  printf("a name : %s, age: %d, addr: %p\n", a.name, a.age, &a.name);
  printf("b name : %s, age: %d, addr: %p\n", b.name, b.age, &b.name);
  printf("p name : %s, age: %d, addr: %p\n", p->name, p->age, &p->name);

  if (p->name) {
    free(p->name);
    p->name = NULL;
  }

  if (p) {
    free(p);
    p = NULL;
  }

  return 0;
}
