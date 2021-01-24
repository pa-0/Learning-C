#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	int filedescriptor;
	char filename[100];
	char message[100];
	
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
	
	printf("Enter A Short Test Message : ");
	scanf("%s",message);

	//int wr;

	if (write(filedescriptor,message,strlen(message)) != strlen(message))
	{
		printf("Could Not Write To File \n");
		exit(-2);	
	}
	else
	{
		printf("Wrote Successfully To %s",filename);
	}

	if (close(filedescriptor) != 0)
	{
		printf("The close operation failed...");
		exit(-3);
	}
	
}
