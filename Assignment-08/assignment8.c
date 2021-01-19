#include <stdio.h>
void main()
{
	int num;
	printf("Enter A Number between 1 and 500 : ");
	scanf("%d",&num);

	int range;
	range = (int)(num/100);
	if (range < 5)
	{
		printf("%d lies between %d and %d\n", num, (range*100),(range+1)*100);	
	}
	else
	{
		printf("Number Out Of Range! \n");
	}
}
