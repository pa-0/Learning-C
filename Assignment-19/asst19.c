#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *cp;
    char *s = "Hello, World! I'm a string literal!";
    
    // allocate memory for the string
    cp = (char *)malloc(128 * sizeof(char));

    // check whether malloc failed
    if (cp == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        return 1;
    }

    printf("Memory was successfully allocated.\n");

    strcpy(cp, "Hello, World! I'm a dynamically allocated string!\n"); // passing in more than 128 chars creates undefined behaviour
    printf("%s", cp);
    puts(s);

    // free the allocated memory
    free(cp);

    return 0;
}