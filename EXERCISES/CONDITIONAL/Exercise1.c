/*
Write a C program to accept two integers and check whether they are equal or not.
Test Data : 15 15
Expected Output :
Number1 and Number2 are equal
*/

#include <stdio.h>

int main()
{

    int num1, num2;

    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("\nEnter the second integer: ");
    scanf("%d", &num2);

    if (num1 == num2)
    {
        printf("\nNumber1 and Number2 are equal.");
    }

    return 0;
}