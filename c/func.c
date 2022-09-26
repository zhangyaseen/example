int max(int, int);
int max(int x, int y);

int main(void) {
  max(10, 20);
  return 0;
}

int max(int x, int y) { return x > y ? x : y; }
