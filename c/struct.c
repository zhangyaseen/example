#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
  char *name;
  int age;
} Person;


void deep_copy(void) {
  Person a;
  a.age = 100;
  a.name = (char *)malloc(sizeof(char) * 10);
  strncpy(a.name, "llllll", 6);

  Person b = a;
  b.name = (char *)malloc(sizeof(char) * 10);
  strncpy(b.name, a.name, 10);

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

}

typedef struct Peo {
  int a;
  char b;
  double c;
  short d;
} Peo;

typedef struct Student {
  char a;
  Peo b;
  double c;
} Student;

typedef struct Pee {
  char a;
  short b;
  int c;
  double d;
} Pee;

void memory_alignment(void) {
  printf("sizeof Peo:%ld, sizeof Stu: %ld\n", sizeof(Peo), sizeof(Student));
  printf("sizeof align Pee: %ld\n", sizeof(Pee));
}

int main(void) {
    deep_copy();

    memory_alignment();

  return 0;
}
