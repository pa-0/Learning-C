#include <stdio.h>

int main()
{

    int numerator, denominator;

    printf("Enter the numerator: \n");
    scanf("%d", &numerator);

    printf("Enter the denominator: \n");
    scanf("%d", &denominator);

    if (numerator % denominator == 0)
    {
        printf("There is no remainder!");
    }
    else
    {
        printf("There is a remainder!");
    }

    return 0;
}