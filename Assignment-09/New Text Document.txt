#include <stdio.h>

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 3) {
        printf("Usage: ./assignment9 Firstname Lastname\n");
        return 1; // Return an error code
    }

    // Print the welcome message
    printf("Hello, %s %s\n", argv[1], argv[2]);

    return 0; // Return success
}
