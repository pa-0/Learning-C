/*
Write a C program to print your name, date of birth, and mobile number.
Expected Output:

Name   : Alexandra Abramov
DOB    : July 14, 1975
Mobile : 99-9999999999
*/

#include <stdio.h>

int main()
{

    char name[] = "Dante Choppa";
    char dateOfBirth[] = "March 8, 1990";
    int phoneNo = 1234567890;

    printf("Name    : %s\n", name);
    printf("DOB     : %s\n", dateOfBirth);
    printf("Mobile  : %d\n", phoneNo);

    return 0;
}
