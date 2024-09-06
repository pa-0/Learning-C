/*
Write a C program to print the following characters in reverse.
Test Characters: 'X', 'M', 'L'
Expected Output:
The reverse of XML is LMX
*/

#include <stdio.h>

int main()
{

    char char1 = 'X';
    char char2 = 'M';
    char char3 = 'L';
    char result[] = {char3, char2, char1, '\0'};

    printf("The reverse of XML is %s", result);

    return 0;
}