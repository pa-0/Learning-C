#include <stdio.h>
#include <stdlib.h>

int main() {
    // initialize vars
    //char firstName[20];
    //char lastName[20];
    char *firstName;
    char *lastName;

    // prompt user to input first and last name
    // %ms dynamically allocates based on length of string
    printf("Enter your first name: ");
    //scanf("%s", firstName);
    scanf("%ms", &firstName);

    printf("Enter your last name: ");
    //scanf("%s", lastName);
    scanf("%ms", &lastName);

    // print welcome message
    printf("Hello %s %s!\n", firstName, lastName);

    free(firstName);
    free(lastName);

    return 0;
}
