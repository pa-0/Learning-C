#include <stdio.h>

/* code written by ChatGPT */

#define PLAYERS 5
#define GAMES 4

int main() {
    int scores[PLAYERS][GAMES];
    int totalScores[PLAYERS] = {0};
    float averages[PLAYERS];
    int i, j;
    int maxPlayerIndex = 0;

    // Input scores for each player and game
    for (i = 0; i < PLAYERS; i++) {
        printf("Enter scores for Player %d:\n", i + 1);
        for (j = 0; j < GAMES; j++) {
            printf("Game %d: ", j + 1);
            scanf("%d", &scores[i][j]);
            totalScores[i] += scores[i][j];
        }
        averages[i] = (float)totalScores[i] / GAMES;
    }

    // Find the player with the highest average
    for (i = 1; i < PLAYERS; i++) {
        if (averages[i] > averages[maxPlayerIndex]) {
            maxPlayerIndex = i;
        }
    }

    // Print the result
    printf("\nPlayer %d has the highest scoring average: %.2f\n", maxPlayerIndex + 1, averages[maxPlayerIndex]);

    return 0;
}
