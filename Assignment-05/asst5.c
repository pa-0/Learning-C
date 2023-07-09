#include <stdio.h>

int main() {
    int n, hours, minutes, seconds;

    // get user input
    printf("Enter the amount of seconds: ");
    scanf("%d", &n);

    // calculate times
    hours = n / 60 / 60;
    minutes = (n - hours*60*60) / 60;
    seconds = n % 60;

    // %0.0f prints a float with no decimal places
    printf("%d seconds is equal to %dh%dm%ds\n", n, hours, minutes, seconds);

    return 0;
}
