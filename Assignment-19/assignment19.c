#include <stdio.h>
#include <stdlib.h>

void main()
{
	char *ptr;
	int size;
	printf("Enter size of array : ");
	scanf("%d",&size);	
	ptr=malloc(size*sizeof(char));

	if (ptr == NULL)
	{
		printf("Memory could not be allocated.");
		exit(1);
	}

	else 
		{
			printf("Memory was successfully allocated.");
			free(ptr);
		}
}
