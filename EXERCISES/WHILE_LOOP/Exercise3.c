/*
Write a C program that calculates the product of numbers from 1 to 5 using a while loop.
*/

#include <stdio.h>

int main()
{

    int count = 1, product = 1;

    while (count <= 5)
    {
        product *= count;
        count++;
    }
    printf("Product of numbers 1 to 5 = %d", product);

    return 0;
}