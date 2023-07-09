#include <stdio.h>

#define TEAM_SIZE 1

typedef struct Employee {
    char firstName[20];
    char lastName[20];
    int employeeID;
    int lastFourSSN;
    char title[20];
} employee;

typedef struct Team {
    employee employees[TEAM_SIZE];
} team;

void displayEmployee(employee e) {
    printf("Employee information for %s %s:\n", e.firstName, e.lastName);
    printf("ID: %d\n", e.employeeID);
    printf("SSN: %d\n", e.lastFourSSN);
    printf("Title: %s Engineer\n\n", e.title);
}

int main() {
    team myTeam;

    for (int i=0; i<TEAM_SIZE; i++) {
        employee *ep = &myTeam.employees[i];

        // n.b. ptr->member == (*ptr).member
        printf("Enter the employee's first name: ");
        scanf("%s", ep->firstName);

        printf("Enter the employee's last name: ");
        scanf("%s", ep->lastName);

        printf("Enter the employee's ID number: ");
        scanf("%d", &ep->employeeID);

        printf("Enter the last 4 digits of the employee's SSN: ");
        scanf("%d", &ep->lastFourSSN);

        printf("Enter the employee's job title: ");
        scanf("%s", ep->title);

        printf("\n");
    }

    for (int i=0; i<TEAM_SIZE; i++) {
        displayEmployee(myTeam.employees[i]);
    }

    return 0;
}
