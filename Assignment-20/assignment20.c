#include <stdio.h>
#include <stdlib.h>

struct Struct
{
	int integer;
	char character;
	float floatchar;
};

void main (void)
{
	struct Struct var;

	printf("Enter Integer Value : ");
	scanf("%d",&var.integer);

	printf("Enter Character Value : ");
	scanf(" %c",&var.character);

	printf("Enter Float Value : ");
	scanf("%f",&var.floatchar);	

	printf("This is the int: %d, this is the char: %c, this is the float: %f\n", var.integer, var.character,var.floatchar);

}
