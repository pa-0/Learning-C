#include <stdio.h>
#include <ctype.h>

int main(){

    // Create a 2D array to store the questions.
    char questions[][100] = {"1. What year did the C language debut?: ",
                             "2. Who is credited with creating C?: ",
                             "3. What is the predecessor of C?: ",
                             "4. Who hacked the Federal Govrnment Of Nigeria?: "};
    
    // Create a 3D array to store the options.
    char options[][4][30] = {
                           {"A. 1969", "B. 1972", "C. 1975", "D. 1965"},
                           {"A. Dennis Ritchie", "B. Mr Robot", "C. John Coman", "D. Dante Choppa"},
                           {"A. C++", "B. C#", "C. B", "D. Assembly"},
                           {"A. Mr Robot", "B. Anonymous", "C. Puppet Master", "D. None of the above"}
                           };

    // Create an array to store the answers.
    char answers[4] = {'B', 'A', 'C', 'C'};

    // Get the number of questions.
    int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);
    //printf("%d", numberOfQuestions);

    char guess;
    int score = 0;

    printf("QUIZ GAME\n");

    for (int i = 0; i < numberOfQuestions; i++)
    {
        printf("************************************\n");
        printf("%s\n", questions[i]);
        printf("************************************\n");

        for (int j = 0; j < numberOfQuestions; j++)
        {
            printf("%s\n", options[i][j]);
        }
        printf("Enter your answer: ");
        scanf(" %c", &guess);
        

        guess = toupper(guess);

        if (guess == answers[i])
        {
            printf("CORRECT!\n");
            score++;
        }
        else{
            printf("WRONG!\n");
        }
        
    }
    
    printf("***********************\n");
    printf("FINAL RESULT: %d/%d\n", score, numberOfQuestions);
    printf("***********************\n");

    return 0;
}