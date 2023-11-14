#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *ptr = malloc(10 * sizeof(char));

	if (ptr == NULL) {
		printf("Memory allocation failed.\n");
		return EXIT_FAILURE;
	}

	printf("Memory was successfully allocated.\n");
	free(ptr);
	return EXIT_SUCCESS;
}
