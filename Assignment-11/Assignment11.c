#include <stdio.h>
#include <stdlib.h> // Required for malloc, realloc, and free

int main()
{
    int *scores = NULL; // Pointer to dynamically allocated memory for scores
    int capacity = 0;   // Current allocated size of the array
    int count = 0;      // Number of elements currently in the array
    int input;          // Variable to store user input

    // Loop to continuously take input from the user
    while (1)
    {
        printf("Enter a test score(or -1 to stop): ");
        scanf("%d", &input);

        if (input == -1)
        {
            break; // Exit the loop if user enters -1
        }

        // Check if we need to expand the array
        if (count == capacity)
        {
            capacity = (capacity == 0) ? 1 : capacity * 2;    // Double the capacity
            scores = realloc(scores, capacity * sizeof(int)); // Resize the array

            if (scores == NULL)
            {
                printf("Memory allocation failed.\n");
                return 1; // Exit if memory allocation fails
            }
        }

        // Add the input score to the array
        scores[count++] = input;
    }
    // Print the elements of the array
    printf("You entered the following scores:\n");
    for (int i = 0; i < count; i++)
    {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    free(scores);

    return 0;
}