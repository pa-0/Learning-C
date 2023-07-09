#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./asst9 firstname lastname!\n");
    } else {
        printf("Hello, %s %s\n", argv[1], argv[2]);
    }

    return 0;
}
