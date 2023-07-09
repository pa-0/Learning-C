#include <stdio.h>

int main() {
    int arr[25] = {0}; // initializes all values to 0

    printf("The array has %lu elements.\n", sizeof(arr)/sizeof(int));

    return 0;
}