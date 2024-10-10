#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(){

    const int MIN = 1;
    const int MAX = 100;
    int guess, number, guesses;

    // Generate a seed with the currrent time
    srand(time(0));

    // Generate a random number
    number = (rand() % MAX) + MIN;
    //printf("%d", number);

    printf("A random number between %d and %d has been selected.\n", MIN, MAX);

    bool keepGoing = true;
    guesses = 0;
    
    while (keepGoing)
    {
        printf("Guess the number: ");
        scanf("%d", &guess);
        
        if (guess > number)
        {
            printf("Too High!\n");
        }
        else if(guess < number){
            printf("Too Low!\n");
        }
        else{
            printf("\nYou Are Correct!\n");
            keepGoing = false;
        }
        guesses ++;               
    }

    printf("***************************\n");
    printf("The number is %d.\n", number);
    printf("It took you %d guesses.\n", guesses);
    printf("***************************\n");


    return 0;
}