#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    int heads = 0;
    int tails = 0;

    // seed the pseudo-random number generator
    srand(time(0));

    printf("How many times would you like to flip the coin? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        if (rand() % 2 == 0) {
            heads++;
        } else {
            tails++;
        }
    }

    printf("After flipping the coin %d times, the results were\n%d heads\n%d tails\n", n, heads, tails);
    
    return 0;
}
