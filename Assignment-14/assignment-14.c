#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int var_int = 42;
	int *ptr_int = &var_int;

	printf("The value of our pointer is: %d", ptr_int);
	return EXIT_SUCCESS;
}
