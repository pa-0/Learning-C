#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int flips, heads, tails;
	srand(time(NULL));

	printf("How many times would you like to flip the coin? ");
	scanf("%d", &flips);

	int i = 0;
	while (i < flips) {
		int flip = rand() % 2;
		i++;

		if (flip == 1) {
			heads++;
		} else {
			tails++;
		}
	}

	printf("After flipping the coin %d times, the results were\n%d heads\n%d tails\n", flips, heads, tails);

	return 0;
}
