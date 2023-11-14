#include <stdio.h>

// no difference between printf and puts
// puts is the simple choice and adds a new line in the end and printfwrites the output from a formatted string.

void hello(void)
{
        char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33, '\0'};

        puts(array);
}

int main(void) 
{
        hello();
}
