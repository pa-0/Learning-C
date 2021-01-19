#include <stdio.h>
#include<malloc.h>

int *num_rem(int n, int d)
{
	
	int *nd=malloc(2);
	nd[0]=(int)(n/d);
	nd[1]=n%d;
	return nd;
}

int main(void)
{
  
  //initialize our vars and get values for them
  int numerator, denominator;
  printf("Enter a numerator: ");
  scanf("%d", &numerator);
  printf("Enter a denominator: ");
  scanf("%d", &denominator);

  int *arr;
  arr=num_rem(numerator,denominator);

  if (arr[1] == 0)
  {
  	printf("There is NOT a remainder!");
  }
  else
  {
  	printf("There is a remainder!");
  }

  return 0;
}
