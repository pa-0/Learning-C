#include <stdio.h>
#include <stdlib.h>

// https://stackoverflow.com/questions/4096304/define-a-function-before-main
// Explains why a function should be declared before main:
// easy to organize when a new function has to use another one
void hello(void);

int main(void) {
	hello();

	return EXIT_SUCCESS;
}

void hello(void) {
	printf("Hello, World!\n");
}
