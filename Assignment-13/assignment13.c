#include <stdio.h>
#define PLAYERS 5
#define GAMES 4

void main()
{
	int table[GAMES][PLAYERS];
	int i,j,maxpos;
	float max,avg,sum;

	for (i=0;i<GAMES;i++)
	{
		printf("Game #%d\n",(i+1));
		for(j=0;j<PLAYERS;j++)
		{
			printf("Enter scoring total for Player #%d : ",(j+1));
			scanf("%d",&table[i][j]);
		}
	}

	maxpos=PLAYERS-1;
	sum=0;
	max = 0;
	avg = 0;

	for(j=0;j<PLAYERS;j++)
	{
		sum=0;
		for (i=0;i<GAMES;i++)
		{
			sum=sum+table[i][j];
		}

		avg = sum/GAMES;
		if(avg > max)
		{
			max=avg;
			maxpos=j;
		}

	}
	printf("Player #%d had the highest scoring average at %.2f points per game.",(maxpos+1),(float)(int)max);
}