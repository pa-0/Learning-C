#include <stdio.h>
#include <stdlib.h>

struct stats {
	float points;
	int games;
};

int main(void) {
	int i, player_num;
	float average;
	struct stats player[5];

	for (i = 0; i < 5; i++) {
		player_num = i + 1;
		printf("Enter Player %d's point total: ", player_num);
		scanf("%f", &player[i].points);
		
		printf("Enter Player %d's game total: ", player_num);
		scanf("%d", &player[i].games);

		printf("\n");
	}

	for (i = 0; i < 5; i++) {
		player_num = i + 1;
		average = player[i].points / player[i].games;
		
		printf("Player %d's scoring average was %.2f ppg.\n", player_num, average);
	}

	return EXIT_SUCCESS;
}
