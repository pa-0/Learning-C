#include <stdio.h>

#define PLAYERS 5

typedef struct Stats {
    int points;
    int games;
} stats;

stats playerStats[PLAYERS];

double scoringAverage(stats *s);

int main() {
    // prompt user for player data
    for (int i=0; i<PLAYERS; i++) {
        printf("Enter Player %d's point total: ", i+1);
        scanf("%d", &playerStats[i].points);

        printf("Enter Player %d's game total: ", i+1);
        scanf("%d", &playerStats[i].games);
    }

    // calculate scoring average and display result
    for (int i=0; i<PLAYERS; i++) {
        printf("Player %d's scoring average was %0.2fppg.\n", i+1, scoringAverage(&playerStats[i]));
    }

    return 0;
}

double scoringAverage(stats *s) {
    return (double)s->points/s->games;
}