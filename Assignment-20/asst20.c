#include <stdio.h>

struct MyStruct {
    int n;
    char c;
    float f;
};

int main() {
    struct MyStruct s1;
    s1.n = 50;
    s1.c = 'W';
    s1.f = 3.14;

    printf("This is the int: %d, this is the char: %c, this is the float: %0.2f\n", s1.n, s1.c, s1.f);

    return 0;
}