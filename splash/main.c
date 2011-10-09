#include "utils.h"

int main() {
    int a = 10;
    int b = 20;
    swap(a, b);
    printf("a=%d, b=%d\n", a, b);
    a = -a;
    printf("a=%d\n", a);
    return 0;
}
