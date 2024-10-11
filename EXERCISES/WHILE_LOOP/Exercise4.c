/*
Write a C program that prompts the user to input a series of numbers until they input a duplicate number. Use a while loop to check for duplicates.
*/

#include <stdio.h>

int main()
{

    int number, previous, duplicate;

    printf("Enter a number: ");
    scanf("%d", &number);

    while (1)
    {
        previous = number;

        printf("\nEnter another number: ");
        scanf("%d", &number);

        printf("Current Number: %d\n", number);
        // printf("Previous Number: %d\n", previous);

        if (number == previous)
        {
            break;
        }
    }
    duplicate = number;

    printf("Duplicate: %d", duplicate);

    return 0;
}