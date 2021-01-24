#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct stats {
	int points;
	int games;
};

struct stats players[SIZE];

void main()
{
	int i;
	float avg;

	for (i=0;i<SIZE;i++)
	{
		printf("Enter Player %d's point total : ",(i+1));
		scanf("%d",&players[i].points);

		printf("Enter Player %d's game total : ",(i+1));
		scanf("%d",&players[i].games);
	}

	for(i=0;i<SIZE;i++)
	{
		avg=(players[i].points)/(players[i].games);
		printf("Player %d's scoring average was %.2f ppg\n",(i+1),avg);
	}
}
