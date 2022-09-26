
void basic(void) {
  int a = 10;
  int b = 20;

  const int *p = &a;
  p = &b;
  // *p = 20 error

  int *const q = &a;
  *q = 100;
  // q = &b; error
}

int main(void) {
  basic();
  return 0;
}