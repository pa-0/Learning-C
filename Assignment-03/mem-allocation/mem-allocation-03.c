#include <stdlib.h>
#include <stdio.h>

/*
** Write a function to receive a byte c (possibly representing an ASCII character) and transforme it 
** into a string, i.e., return a string of length 1 having c as it sole element.
*/

int main() {
    char *c = malloc(1);

    scanf("%c", c);
    printf("%c\n", *c);

    return 0;
}