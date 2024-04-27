#include <stdio.h>

int main()
{

    float seconds;

    printf("Enter the amount of seconds: \n");
    scanf("%f", &seconds);

    float hours, minutes, remainingSeconds;

    hours = (int)(seconds / 3600);
    minutes = (int)((seconds - (hours * 3600)) / 60);
    remainingSeconds = (seconds - (hours * 3600) - (minutes * 60));

    printf("%0.f seconds is equal to %0.f hours, %0.f minutes, and %0.f seconds\n", seconds, hours, minutes, remainingSeconds);

    return 0;
}