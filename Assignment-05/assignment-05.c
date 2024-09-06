#include <stdio.h>

int main() {
    int seconds, minutes, hours;

    printf("Enter the number of seconds: ");
    scanf("%d", &seconds);

    minutes = seconds / 60;
    hours = minutes / 60;

    printf("Time in minutes: %d\n", minutes);
    printf("Time in hours: %d\n", hours);

    return 0;
}