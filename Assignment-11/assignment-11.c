#include <stdio.h>
#include <string.h>

int main(void) {
	float sum;
	int num_of_scores = 1;
	int scores[8] = {0};

	int score;
	printf("Enter a test score: ");
	scanf("%d", &score);
	scores[0] = score;

	for (int i = 1; i < 8; i++) {
		char choice[1];
		printf("Would you like to continue? Y/N ");
		scanf("%s", &choice);

		if (!strcmp(choice, "Y")) {
			printf("Enter a test score: ");
			scanf("%i", &score);
			scores[i] = score;
			num_of_scores++;
		} else {
			break;
		}
	}
	
	for (int j = 0; j < num_of_scores; j++) {
		sum += scores[j];
	}
	float average = sum / num_of_scores;
	printf("%.2f is the average.", average);

	return 0;
}
