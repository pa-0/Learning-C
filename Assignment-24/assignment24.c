#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void main (void)
{
	int filedescriptor;
	char filename[50];
	
	printf("Enter Your FileName : ");
	scanf("%s",filename);

	filedescriptor = open(filename, O_WRONLY | O_CREAT, S_IRWXU);

	if (filedescriptor < 0)
	{
		printf("The operation Failled. Exiting\n");
		exit(-1);
	}
	else 
	{
		printf("File %s Has Been Created \n",filename);
	}
	
}
