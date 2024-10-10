#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{

    int coinFlip = 0, heads = 0, tails = 0, coinSide = 0;

    printf("How many times would you like to flip the coin? ");
    scanf("%d", &coinFlip);

    srand(time(0));

    for (int i = 0; i < coinFlip; i++)
    {
        coinSide = rand() % 10;
        
        // Even numbers = Head and Odd numbers = Tail.
        if (coinSide % 2 == 0)
        {
            heads++;
        }
        else{
            tails++;
        }
        
    }
    
    

    printf("After flipping the coin %d times, the results were: \n", coinFlip);
    printf("%d Heads\n%d Tails", heads, tails);

    return 0;
}