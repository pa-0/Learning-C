/*
Write a C program that prompts the user to input a series of integers until the user stops entering 0 using a while loop. Calculate and print the sum of all the positive integers entered.
*/

#include <stdio.h>

int main()
{

    int number, sum;

    printf("Enter a number: ");
    scanf("%d", &number);

    sum = number;

    while (number != 0)
    {
        printf("\nEnter another number(enter 0 to stop): ");
        scanf("%d", &number);

        if (number > 0)
        {
            sum += number;
        }
    }
    printf("Sum: %d", sum);

    return 0;
}