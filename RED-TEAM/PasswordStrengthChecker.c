#include <stdio.h>
#include <string.h>

void checkPasswordLength(char *ptr, int *ptr2)
{
    int length = strlen(ptr);
    printf("%d\n", length);

    // check if password length is less than 8 characters.
    if (length < 8)
    {
        printf("Password is too weak!\n");
    }
    else if (length >= 8 && length <= 12)
    {
        *ptr2 = 10;
    }
    else if (length > 12)
    {
        *ptr2 = 20;
    }
}

void checkUpperCaseLetters(char *ptr, int *ptr2)
{
    /* code */
}

void checkLowerCaseLetters(char *ptr, int *ptr2)
{
    /* code */
}

void checkDigits(char *ptr, int *ptr2)
{
    /* code */
}

void checkSpecialCharacter(char *ptr, int *ptr2)
{
    /* code */
}

int main()
{

    char password[100];
    int strengthScore = 0;
    char *ptr = password;
    int *ptr2 = &strengthScore;

    printf("Enter a password to check the strength: ");
    scanf("%s", password);

    checkPasswordLength(ptr, ptr2);

    printf("Strength = %d", strengthScore);

    return 0;
}