// gcc -E define.c -o define.i
// gcc -S define.i -o define.s

#define MAX 100

int main(void) {
    int a;
    a = 100;

    int arr[100+MAX];

    #if 0
    int b = 0;
    #endif

    return 0;
}