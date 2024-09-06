/*
Write a C program to check whether a given number is even or odd.
Test Data : 15
Expected Output :
15 is an odd integer
*/

#include <stdio.h>

int main()
{

    int num;

    printf("Enter any integer: ");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("\n%d is an even integer", num);
    }
    else
    {
        printf("\n%d is an odd integer", num);
    }

    return 0;
}