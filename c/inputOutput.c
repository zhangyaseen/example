#include <stdio.h>

void output_putchar(void) {
  putchar('a');
  printf("\noutput end....\n");
}

void output_puts(void) {
  printf("begin puts:\n");
  puts("hello world"); // 自动追加回车
  printf("output puts end\n");
}

void input_getchar(void) {
  printf("begin getchar:\n");
  char ch1 = getchar();
  printf("getchar ch1: %c\n", ch1);

  getchar(); // 读取输入的回车

  printf("begin getchar:\n");
  char ch2 = getchar();
  printf("getchar ch2: %c\n", ch2);

  getchar(); // 读取输入的回车
  printf("end getchar.....\n");
}

void input_scanf(void) {
  printf("begin scanf char:\n");
  char ch1;
  scanf("%c", &ch1);
  printf("scanf ch1: %c\n", ch1);

  printf("begin scanf int:\n");
  int a1;
  scanf("%d", &a1);
  printf("scanf a1: %d\n", a1);
}

void input_string_scanf(void) {
  char str[10] = {};
  printf("begin string scanf:\n");

  scanf("%s", str); // 不安全的，如果越界，就会abort. 中间不能使用空格
  printf("string scanf str: %s\n", str);
}

void input_string_gets(void) {
  char str[10] = {};
  printf("begin string gets:\n");
  gets(str); // 不安全的，如果越界，就会abort. 中间可以使用空格
  printf("string gets str: %s\n", str);
}

void input_string_fgets(void) {
  char str[10] = {};
  printf("begin string fgets:\n");
  fgets(str, sizeof(str), stdin);
  printf("string fgets str: %s\n", str);
}

void output_fputs(void) {
  printf("begin puts:\n");
  fputs("hello world", stdout); // 不追加回车
  printf("[output puts end]\n");
}

int main(void) {
  output_putchar();
  output_puts();
  output_fputs();

  input_getchar();
  input_scanf();
  input_string_gets();
  input_string_scanf();
  input_string_fgets();

  return 0;
}