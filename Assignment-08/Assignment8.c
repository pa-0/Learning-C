#include <stdio.h>

int main()
{

    int number;

    printf("Enter a number between 1 and 500: \n");
    scanf("%d", &number);

    if (number > 0 && number < 101)
    {
        printf("Your number is between 1 and 100!\n");
    }
    else if (number > 100 && number < 201)
    {
        printf("Your number is between 100 and 200!\n");
    }
    else if (number > 200 && number < 301)
    {
        printf("Your number is between 200 and 300!\n");
    }
    else if (number > 300 && number < 401)
    {
        printf("Your number is between 300 and 400!\n");
    }
    else if (number > 400 && number < 501)
    {
        printf("Your number is between 400 and 500!\n");
    }
    else
    {
        printf("Invalid number!");
    }

    return 0;
}