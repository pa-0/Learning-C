#include <stdio.h>

int main() {
    int n = 17;
    int *np = &n;

    printf("The value of int variable is: %d\n", n);
    printf("The value of the pointer to the int variable is: %p\n", np);
    printf("The memory address of the int variable is: %p\n", &n);
    printf("The value held at the memory location that the pointer is pointing to is: %d\n", *np);

    return 0;
}
