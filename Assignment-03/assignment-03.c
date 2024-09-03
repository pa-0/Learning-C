#include <stdio.h>

int main() {
    char name[20];
    char lastName[20];

    printf("Enter your first name: ");
    scanf("%s", name);

    printf("Enter your last name: ");
    scanf("%s", lastName);

    printf("Hello, %s %s.\n", name, lastName);

    return 0;
}
