#include <stdio.h>

int main()
{

    // char firstName[10];
    // char lastName[10];

    // Dynamically allocate the array size of your char variable
    char *firstName;
    char *lastName;

    printf("Enter your first name: \n");
    scanf("%ms", &firstName);

    printf("Enter your last name: \n");
    scanf("%ms", &lastName);

    printf("Welcome, %s %s!", firstName, lastName);

    return 0;
}