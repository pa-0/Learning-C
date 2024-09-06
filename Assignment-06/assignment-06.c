#include <stdio.h>

int main() {
    int numerator, denominator, remainder;

    printf("Enter a numerator: ");
    scanf("%d", &numerator);

    printf("Enter a denominator: ");
    scanf("%d", &denominator);

    remainder = numerator % denominator;
    if (remainder == 0) {
        printf("There is no remainder.\n");
        return 0;
    }

    printf("There is a remainder: %d\n", remainder);

    return 0;
}
