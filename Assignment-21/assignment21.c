#include <stdlib.h>
#include <stdio.h>

struct employee
{
	char firstname[100];
	char lastname[100];

	long int ID;
	int SSN;

	char title[100];	
};

struct employeeList
{
	struct employee employee1;
	struct employee employee2;
};

void displayEmployee(struct employee *s)
{
	printf("Employee Information For %s %s\nID : %d\nSSN : %d\nTitle : %s Engineer\n\n",s->firstname,s->lastname,s->ID,s->SSN,s->title);
}

void inputData(struct employee *s)
{
	printf("Enter Employee's First Name : ");
	scanf("%s",s->firstname);

	printf("Enter Employee's Last Name : ");
	scanf("%s",s->lastname);

	printf("Enter Employee ID : ");
	scanf("%d",&(s->ID));

	printf("Enter SSN Number : ");
	scanf("%d",&(s->SSN));

	printf("Enter the Employee's Job Title (do not include the word 'Engineer') : ");
	scanf("%s",s->title);	
}

void main()
{
	struct employeeList EMPLOYEE_LIST;
	inputData(&(EMPLOYEE_LIST.employee1));
	printf("\n");
	
	inputData(&(EMPLOYEE_LIST.employee2));
	printf("\n");

	displayEmployee(&EMPLOYEE_LIST.employee1);
	displayEmployee(&EMPLOYEE_LIST.employee2);
}
