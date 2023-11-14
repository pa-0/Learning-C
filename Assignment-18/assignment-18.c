#include <stdio.h>

// no difference between puts and printf

void hello(void)
{
        char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33};

        puts(array);
}

int main(void) 
{
        hello();
}
