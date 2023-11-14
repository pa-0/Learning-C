#include <stdio.h>
#include <stdlib.h>

struct example {
	int integer;
};


int main(void) {
	struct example test;
	struct example *ptr;
	ptr = &test;

	test.integer = 5;
	printf("%i\n", test.integer);

	(*ptr).integer = 6;
	printf("%i\n", (*ptr).integer);

	ptr->integer = 7;
	printf("%i\n", ptr->integer);

	return EXIT_SUCCESS;
}
