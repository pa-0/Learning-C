#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// prints out the memory address because an array is a pointer to the first element of the array
	// https://www.w3schools.com/c/c_pointers_arrays.php
	printf("%d", array);

	return EXIT_SUCCESS;
}
