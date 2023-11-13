#include <stdio.h>

int main(void) {
	char first_name[50];
	char last_name[50];

	printf("Enter your first name: ");
	scanf("%s", &first_name);
	printf("Enter your last name: ");
	scanf("%s", &last_name);
	printf("Hello %s %s!", first_name, last_name);

	return 0;
}
