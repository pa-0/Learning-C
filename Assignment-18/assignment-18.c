#include <stdio.h>

// output: Hello, World!0�g(�
// Unexpected characters printed in the end
void hello(void)
{
        char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33};

        printf("%s", array);
}

int main(void) 
{
        hello();
}
