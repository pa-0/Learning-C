#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // write only, create file if it doesn't exist, chmod 700
    int fd = open("foo.txt", O_WRONLY | O_CREAT, S_IRWXU);
    if (fd == -1) {
        printf("File could not be opened.\n");
        return 1;
    }

    printf("File opened.\n");
    return 0;
}