#include <stdio.h>

int main() {
    int a, b;

    printf("Enter a numerator: ");
    scanf("%d", &a);
    printf("Enter a denominator: ");
    scanf("%d", &b);

    if (a % b != 0) {
        printf("There is a remainder!\n");
    } else {
        printf("There is NOT a remainder!\n");
    }

    return 0;
}
