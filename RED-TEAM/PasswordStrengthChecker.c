#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_OF_COMMON_PASSWORDS 6

struct Flags
        {
            int length,
            digits,
            uppercase,
            lowercase,
            specialCharacter;
        };

void checkPasswordLength(char *pPassword, int *pStrengthScore, struct Flags *flag)
{
    // Get the length of the password.
    int length = strlen(pPassword);
    printf("==================================\n");
    printf("The password is %d character long.\n", length);
    printf("==================================\n");

    // check if password length is less than 8 characters.
    if (length < 8)
    {
        // printf("Password is too weak!\n");
        printf("==================================\n");
    }
    else if (length >= 8 && length <= 12)
    {
        *pStrengthScore = 10;
        flag->length = 1;
    }
    else if (length > 12)
    {
        *pStrengthScore = 20;
        flag->length = 1;
    }
}

void checkUpperCaseLetters(char *pPassword, int *pStrengthScore, struct Flags *flag)
{
    // Check if password contains Upper Case letters.
    while (*pPassword) {
        if (isupper(*pPassword)){
            *pStrengthScore = *pStrengthScore + 10;
            flag->uppercase = 1;
            break;
        }
        pPassword++;
    }
}

void checkLowerCaseLetters(char *pPassword, int *pStrengthScore, struct Flags *flag)
{
    // Check if password contains Lower Case letters.
    while (*pPassword) {
        if (islower(*pPassword)){
            *pStrengthScore = *pStrengthScore + 10;
            flag->lowercase = 1;
            break;
        }
        pPassword++;
    }
}

void checkDigits(char *pPassword, int *pStrengthScore, struct Flags *flag)
{
    // Check if password contains Digits.
    while (*pPassword) {
        if (isdigit(*pPassword)){
            *pStrengthScore = *pStrengthScore + 10;
            flag->digits = 1;
            break;
        }
        pPassword++;
    }
}

void checkSpecialCharacter(char *pPassword, int *pStrengthScore, struct Flags *flag)
{
    // Check if password contains Special Character.
    while (*pPassword) {
        if (!isalnum(*pPassword)){
            *pStrengthScore = *pStrengthScore + 20;
            flag->specialCharacter = 1;
            break;
        }
        pPassword++;
    }
}

void checkRepeatedCharacter(char *pPassword, int *pStrengthScore)
{
    // Check for repeated characters in the password.
    int length = strlen(pPassword);

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (pPassword[i] == pPassword[j])
            {
                *pStrengthScore = *pStrengthScore - 5;
            }
        }
        
        
    
    }
        
        pPassword++;
}        

void checkForCommonPasswords(char *pPassword, int *pStrengthScore)
{
    // Check if the password is found among common passwords.
    char *commonPasswords[NUM_OF_COMMON_PASSWORDS] = {"password1234", "12345678", "qwerty", "password", "passwd", "Password123"};

    // Loop through the array of common password and compare with the user's password.
    for (int i = 0; i < NUM_OF_COMMON_PASSWORDS; i++)
    {
        if (strcmp(pPassword, commonPasswords[i]) == 0)
        {
            printf("Your password is too common!\n");
            *pStrengthScore = *pStrengthScore - 5;
            break;
        }
    }
    
}

void passwordComplexity(char *pPassword, int *pStrengthScore, struct Flags flag)
{
    // Evaluate the Password’s Complexity.
    if (flag.length == 1  && flag.uppercase == 1  && flag.lowercase == 1  && flag.digits == 1  && flag.specialCharacter == 1)
    {
        printf("High Complexity\n");
        printf("==================================\n");
        *pStrengthScore = *pStrengthScore + 20;
    }
    else if (flag.length == 1  && flag.digits == 1  && flag.lowercase == 1)
    {
        printf("Average Complexity\n");
        printf("==================================\n");
        *pStrengthScore = *pStrengthScore + 10;
    }
    else{
        printf("Low Complexity\n");
        printf("==================================\n");
    }
    
    
    
}

void passwordStrength(int *pStrengthScore)
{
    // Evaluate the password strength.
    if (*pStrengthScore >= 70)
    {
        printf("Your password is strong!\n");
        printf("==================================\n");
    }
    else if (*pStrengthScore >= 40 && *pStrengthScore < 70)
    {
        printf("Your password is moderate!\n");
        printf("==================================\n");
        printf("Suggestions: Add digits,\nSpecial characters\nand Uppercase letters.\n");
        printf("==================================\n");
    }
    else{
        printf("Your password is weak!\n");
        printf("==================================\n");
        printf("Suggestions: Add digits,\nSpecial characters\nand Uppercase letters.\n");
        printf("==================================\n");
    }
    
    
}

int main()
{

    char exit;
    bool keepGoing = true;
    char password[100];
    int strengthScore = 0;
    char *pPassword = password;
    int *pStrengthScore = &strengthScore;

    struct Flags flag;

    
    do
    {
        printf("Enter a password to check the strength: ");
        scanf("%s", password);
        

        checkForCommonPasswords(pPassword, pStrengthScore);
        checkPasswordLength(pPassword, pStrengthScore, &flag);
        checkUpperCaseLetters(pPassword, pStrengthScore, &flag);
        checkLowerCaseLetters(pPassword, pStrengthScore, &flag);
        checkDigits(pPassword, pStrengthScore, &flag);
        checkSpecialCharacter(pPassword, pStrengthScore, &flag);
        checkRepeatedCharacter(pPassword, pStrengthScore);
        passwordComplexity(pPassword, pStrengthScore, flag);
        passwordStrength(pStrengthScore);

        printf("Strength = %d\n", strengthScore);
        printf("==================================\n");

        printf("Would you like to check another password?(y/n):");
        scanf(" %c", &exit);
        printf("==================================\n");

        if (exit == 'n')
        {
            keepGoing = false;
        }
        else if (exit == 'y')
        {
            keepGoing = true;
        }
        
    } while (keepGoing);
    

    return 0;
}