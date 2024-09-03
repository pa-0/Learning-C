#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr;
    ptr = malloc(2);
    
    printf("%p\n", ptr);

    return 0;
}
