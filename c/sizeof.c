// gcc -S sizeof.c -o sizeof.s

int main(void) {
    int a;
    int b = sizeof(a);
    return 0;
}