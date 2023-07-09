#include <stdio.h>

void hello(void)
{
	char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33};

	//printf("%s", array); // returns an unreadable char at the end - doesn't know when to terminate string
    puts(array); // adds '\n'
}

int main(void) 
{
	hello();
}
