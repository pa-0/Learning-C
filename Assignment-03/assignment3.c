#include <stdio.h>
#include <stdlib.h>
void main()
{
char *first;
char *last;

printf("Enter Your First Name : ");
scanf("%ms",&first); // Allocated On The Heap

printf("Enter Your Last Name : ");
scanf("%ms",&last); // Allocated On The Heap

printf("Knock Knock %s %s, Time To Wake Up !",first,last);
free(first); // Freeing The Memory
free(last); // Freeing The Memory
}
