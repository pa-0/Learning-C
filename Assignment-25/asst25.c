#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, writeRet;

    // write only, create file if it doesn't exist, chmod 700
    fd = open("foo.txt", O_WRONLY | O_CREAT, S_IRWXU);
    if (fd == -1) {
        fprintf(stderr, "File could not be opened.\n");
        return 1;
    }

    printf("File opened.\n");

    writeRet = write(fd, "Writing test data to the file\n", 30);
    if (writeRet != 30) {
        fprintf(stderr, "File write failed.\n");
        return 1;
    }

    printf("File write successful.\n");

    if (close(fd) != 0) {
        fprintf(stderr, "File could not be closed.\n");
        return 1;
    }

    printf("File closed.\n");

    return 0;
}