#include <stdio.h>
#include <stdlib.h>

// To understand the way this works, you need to know that a string
// in C is nothing but an array of characters terminated in '\0'. And
// an array is nothing but a pointer to a memory address containing a sequence of
// the desired type.

int main() {
    char *name;
    char *lastName;

    printf("Enter your first name: ");
    scanf("%ms", &name);

    printf("Enter your last name: ");
    scanf("%ms", &lastName);

    printf("Hello, %s %s.\n", name, lastName);

    free(name);
    free(lastName);

    return 0;
}
