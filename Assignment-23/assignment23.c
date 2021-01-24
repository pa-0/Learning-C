#include <stdio.h>
#include <stdlib.h>

struct Struct{
	int integer;
};

void main (void)
{
	struct Struct *ptr;
	struct Struct test;

	ptr = &test;

	printf("Enter a number : ");
	scanf("%d",&(test.integer));

	printf("Printing Using . %d\n", test.integer);
	printf("Printing Using * %d\n", (*ptr).integer);
	printf("Printing Using -> %d\n", ptr->integer);

}
