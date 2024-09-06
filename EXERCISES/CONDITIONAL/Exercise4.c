/*
Write a C program to find whether a given year is a leap year or not.
Test Data : 2016
Expected Output :
2016 is a leap year.
*/

#include <stdio.h>

int main()
{
    int year;

    printf("Enter any year: ");
    scanf("%d", &year);

    // Check if the year is a leap year
    if (year % 400 == 0)
    {
        printf("\n%d is a leap year.", year);
    }
    else if (year % 100 == 0)
    {
        printf("\n%d is not a leap year.", year);
    }
    else if (year % 4 == 0)
    {
        printf("\n%d is a leap year.", year);
    }
    else
    {
        printf("\n%d is not a leap year.", year);
    }

    return 0;
}
