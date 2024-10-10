#include <stdio.h>


int main(){

    int num = 4212;
    int *pNum = NULL;
    pNum = &num;

    // printf("%p\n", pNum);
    // *pNum = 443;
    printf("The value of our pointer is: %d\n", *pNum);
    // printf("%d", num);
    return 0;
}