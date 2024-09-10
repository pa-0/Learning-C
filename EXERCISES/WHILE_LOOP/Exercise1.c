/*
Write a C program to print numbers from 0 to 10 and 10 to 0 using two while loops.
*/
#include <stdio.h>

int main()
{

    int count = 0;

    while (count < 11)
    {
        printf("%d\n", count);
        count++;
    }

    count = 10;

    while (count > -1)
    {
        printf("\n%d", count);
        count--;
    }

    return 0;
}