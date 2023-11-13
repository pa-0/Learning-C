#include <stdio.h>

int main(void) {
	int int_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int array_length = sizeof(int_array) / sizeof(int_array[0]);

	printf("The array has %d elements.", array_length);

	return 0;
}
