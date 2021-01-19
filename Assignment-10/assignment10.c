#include <stdio.h>
#define arrSize(x)  (sizeof(x) / sizeof((x)[0]))

void main()
{
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("The array has %d elements.\n",arrSize(array));
}
