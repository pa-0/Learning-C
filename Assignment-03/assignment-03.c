#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	char *buffer;
	
	buffer = (char *) malloc(101);
	printf("Enter your first name: ");
	scanf(" %100[^\n]", buffer);
	char *first_name = (char *) malloc(strlen(buffer) + 1);
	strcpy(first_name, buffer);

	buffer = (char *) realloc(buffer, 101);
	printf("Enter your last name: ");
	scanf(" %100[^\n]", buffer);
	char *last_name = (char *) malloc(strlen(buffer) + 1);
	strcpy(last_name, buffer);

	printf("Hello %s %s!", first_name, last_name);

	free(buffer);

	return 0;
}
