#include <stdio.h>

int main(void) {
	int seconds;
	printf("Enter the amoutn of seconds: ");
	scanf("%d", &seconds);

	int num_hours = seconds / 3600;
	int num_minutes = seconds % 3600 / 60;
	int num_seconds = seconds % 3600 % 60;

	printf("%d seconds is equal to %d hours, %d minutes, and %d seconds.", seconds, num_hours, num_minutes, num_seconds);

	return 0;
}
