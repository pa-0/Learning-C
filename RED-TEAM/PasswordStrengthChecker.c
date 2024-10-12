#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void checkPasswordLength(char *pPassword, int *pStrengthScore)
{
    // Get the length of the password.
    int length = strlen(pPassword);
    printf("%d\n", length);

    // check if password length is less than 8 characters.
    if (length < 8)
    {
        printf("Password is too weak!\n");
    }
    else if (length >= 8 && length <= 12)
    {
        *pStrengthScore = 10;
    }
    else if (length > 12)
    {
        *pStrengthScore = 20;
    }
}

void checkUpperCaseLetters(char *pPassword, int *pStrengthScore)
{
    // Check if password contains Upper Case letters.
    while (*pPassword) {
        if (isupper(*pPassword)){
            *pStrengthScore = *pStrengthScore + 10;
            break;
        }
        pPassword++;
    }
}

void checkLowerCaseLetters(char *pPassword, int *pStrengthScore)
{
    // Check if password contains Lower Case letters.
    while (*pPassword) {
        if (islower(*pPassword)){
            *pStrengthScore = *pStrengthScore + 10;
            break;
        }
        pPassword++;
    }
}

void checkDigits(char *pPassword, int *pStrengthScore)
{
    // Check if password contains Digits.
    while (*pPassword) {
        if (isdigit(*pPassword)){
            *pStrengthScore = *pStrengthScore + 10;
            break;
        }
        pPassword++;
    }
}

void checkSpecialCharacter(char *pPassword, int *pStrengthScore)
{
    // Check if password contains Special Character.
    while (*pPassword) {
        if (!isalnum(*pPassword)){
            *pStrengthScore = *pStrengthScore + 20;
            break;
        }
        pPassword++;
    }
}

void checkRepeatedCharacter(char *pPassword, int *pStrengthScore)
{
    // Check for repeated characters in the password.
    
    bool keepGoing = true;
    while (keepGoing)
    {
        for (int i = 1; i < strlen(pPassword); i++)
        {
            //printf("%c\n",  pPassword[i]);
            // printf("%c\n",  pPassword[j]);
            if (*pPassword == pPassword[i])
            {
                printf("%c = Same\n", *pPassword);
                *pStrengthScore = *pStrengthScore - 5;
                keepGoing = false;
            }
        
        }
        printf("%c\n", *pPassword);
        *pPassword++;
    }
    
    // for (int i = 0; i < strlen(pPassword); i++)
    // {
        
        
    //     //*pStrengthScore = *pStrengthScore + 10;    
    // }
        
        
}

int main()
{

    char password[100];
    int strengthScore = 0;
    char *pPassword = password;
    int *pStrengthScore = &strengthScore;

    printf("Enter a password to check the strength: ");
    scanf("%s", password);

    checkPasswordLength(pPassword, pStrengthScore);
    checkUpperCaseLetters(pPassword, pStrengthScore);
    checkLowerCaseLetters(pPassword, pStrengthScore);
    checkDigits(pPassword, pStrengthScore);
    checkSpecialCharacter(pPassword, pStrengthScore);
    checkRepeatedCharacter(pPassword, pStrengthScore);

    printf("Strength = %d", strengthScore);

    return 0;
}