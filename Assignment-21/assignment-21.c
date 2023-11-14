#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
	char first_name[20];
	char last_name[20];
	int employee_id;
	int ssn_last_4;
	char title[20];
} employee1, employee2;

struct staff {
	struct employee employee1;
	struct employee employee2;
} employees;

int main(void) {
	int i;
	for (i = 0; i < 2; i++) {
		struct employee *placeholder = &employees.employee1;

		if (i > 0) {
			placeholder = &employees.employee2;
		}

		printf("Enter the employee's first name: ");
		scanf("%s", &placeholder->first_name);

		printf("Enter the employee's last name: ");
		scanf("%s", &placeholder->last_name);

		printf("Enter the employee's ID number: ");
		scanf("%d", &placeholder->employee_id);

		printf("Enter the last four digits of the employee's SSN: ");
		scanf("%d", &placeholder->ssn_last_4);

		printf("Enter the employee's job title (do not include the word 'Engineer'): ");
		scanf("%s", &placeholder->title);

		printf("\n");
	}


	for (i = 0; i < 2; i++) {
		struct employee *placeholder = &employees.employee1;

		if (i > 0) {
			placeholder = &employees.employee2;
		}

		printf("Employee information for %s %s:\n", placeholder->first_name, placeholder->last_name);
		printf("ID: %d\n", placeholder->employee_id);
		printf("SSN: %d\n", placeholder->ssn_last_4);
		printf("Title: %s Engineer\n", placeholder->title);
		printf("\n");
	}

	return EXIT_SUCCESS;
}
