#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void main()
{
	int i, choice, heads;

	printf("How many times would you like to flip the coin? ");
	scanf("%d",&choice);

	heads=0;
	
	srand(time(0));
	for (i=0;i<choice;i++)
	{
		if (rand()%2==0)
			heads++;

	}
	printf("After flipping the coin %d times, the results were\n%d heads\n%d tails\n",choice,heads,(choice-heads));
}		