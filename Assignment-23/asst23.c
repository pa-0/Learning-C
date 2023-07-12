#include <stdio.h>

struct MyStruct {
    int n;
};

int main() {
    struct MyStruct *sp;
    struct MyStruct s;

    sp = &s;

    s.n = 5;
    printf("%d\n", s.n);

    (*sp).n = 6;
    printf("%d\n", s.n);

    sp->n = 7;
    printf("%d\n", s.n);

    return 0;
}
