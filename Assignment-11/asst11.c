#include <stdio.h>
#include <string.h>

double average(int scores[], int n) {
    int sum;

    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }

    return (double)sum / n;
}

int main() {
    char cont[1];
    int scores[10];
    int i = 0;

    do {
        printf("Enter a test score: ");
        scanf("%d", &scores[i]);

        printf("Would you like to continue (Y/N)? ");
        scanf("%s", cont);

        i++;
    } while (strcmp(cont, "Y") == 0 && i < 10);

    // calculate average and print output
    printf("%0.2f is the average.\n", average(scores, i));

    return 0;
}