#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
	int fileDescriptor;
       	fileDescriptor = open("testfile.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

	if (fileDescriptor < 0) {
		printf("The open operation failed...");
		return EXIT_FAILURE;
	} else {
		printf("The open operation succeeded!\n");
	}

	int writeRtn;

	writeRtn = write(fileDescriptor, "Writing test data to the file", 30);

	if (writeRtn != 30) {
		printf("The write operation failed...");
		return EXIT_FAILURE;
	} else {
		printf("The write operation succeeded!\n");
	}

	if (close(fileDescriptor) < 0) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
