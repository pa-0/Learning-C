#include <stdio.h>

int main()
{

    int task;
    char path[255];
    char key[255];

    printf("FILE ENCRYPTOR / DECRYPTOR\n");
    printf("==========================\n");
    printf("Enter(1) to Encrypt a file\nEnter(2) to Decrypt a file\n");
    scanf("%d", &task);

    //  Validate the user input
    if (task == 1)
    {
        printf("Enter the file path of the file you want to encrypt:\n");
        printf("====================================================\n");
        scanf("%s", &path);
    }
    else if (task == 2)
    {
        printf("Enter the file path of the file you want to decrypt:\n");
        printf("====================================================\n");
        scanf("%s", &path);
    }
    else
    {
        printf("Invalid input!");
    }

    printf("\nEnter an encryption key of your choice: \n");
    printf("=============================================\n");
    scanf("%s", &key);

    FILE *pF = fopen(path, "r");

    // Check if the file exists.
    if (pF == NULL)
    {
        printf("Failed to read file!(Hint: Make sure the file exist)\n");
    }
    else
    {
        // Create a buffer to store the file data.
        char buffer[255];

        // Read the content of the file.
        while (fgets(buffer, 255, pF) != NULL)
        {
            printf("\n%s", buffer);
        }

        fclose(pF);
    }

    return 0;
}