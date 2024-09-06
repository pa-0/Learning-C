/*
Write a C program to check whether a given number is positive or negative.
Test Data : 15
Expected Output :
15 is a positive number
*/

#include <stdio.h>

int main()
{

    int num;

    printf("Enter any number: ");
    scanf("%d", &num);

    if (num >= 0)
    {
        printf("\n%d is a positive number", num);
    }
    else
    {
        printf("\n%d is a negative number", num);
    }

    return 0;
}