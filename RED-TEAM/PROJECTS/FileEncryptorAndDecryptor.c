/*
FILE ENCYPTOR AND DECRYPTOR PROGRAM BY DANTECHOPPAXXX.
==============================================
This program secures sensitive information by converting it into ciphertext (encryption) and reverses this process to retrieve the original data (decryption).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xorEncryptFile(const char *path, const char *key)
{

    FILE *inputFile = fopen(path, "rb");

    // Check if the file exists.
    if (inputFile == NULL)
    {
        printf("Failed to read file!(Hint: Make sure the file exist)\n");
        return;
    }
    else
    {
        // Create a buffer to store the file data.
        unsigned char *buffer;
        long fileSize;

        // Find the size of the file
        fseek(inputFile, 0, SEEK_END); // Move file pointer to the end of the file
        fileSize = ftell(inputFile);   // Get the current file pointer position (file size)
        rewind(inputFile);

        // Allocate memory to store the file contents
        buffer = (unsigned char *)malloc(fileSize * sizeof(unsigned char));
        if (buffer == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(inputFile);
            return;
        }

        // Read the entire file into the buffer
        size_t bytesRead = fread(buffer, sizeof(unsigned char), fileSize, inputFile);

        // Check if the size of bytes read is equal to the file size.
        if (bytesRead != fileSize)
        {
            printf("Error reading file.\n");
            free(buffer);
            fclose(inputFile);
            return;
        }

        printf("File contents read successfully!\n");

        // Create a file to store the binary data.
        FILE *data = fopen("data.bin", "wb");
        if (data == NULL)
        {
            printf("Failed to open file!\n");
            return;
        }

        // Write binary data to a file.
        fwrite(buffer, sizeof(unsigned char), fileSize, data);
        fclose(data);

        printf("\n%s\n", buffer);
        // Cleanup
        free(buffer);
        fclose(inputFile);
    }

    FILE *dataFile = fopen("data.bin", "rb");
    if (dataFile == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    FILE *outputFile = fopen("encrypted.bin", "wb");
    if (outputFile == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    size_t keyLength = strlen(key);
    size_t keyIndex = 0;
    unsigned char buffer;

    // Read the file byte by byte.
    while (fread(&buffer, sizeof(unsigned char), 1, dataFile))
    {
        // XOR the buffer with the key byte.
        buffer ^= key[keyIndex % keyLength];
        keyIndex++;

        // Write the encrypted byte to the output file.
        fwrite(&buffer, sizeof(unsigned char), 1, outputFile);
    }

    // Close the files.
    fclose(dataFile);
    fclose(outputFile);

    printf("File encryption completed!\n");
}

void xorDecryptFile(const char *path, const char *key)
{

    FILE *inputFile = fopen(path, "rb");

    // Check if the file exists.
    if (inputFile == NULL)
    {
        printf("Failed to read file!(Hint: Make sure the file exist)\n");
        return;
    }
    else
    {
        FILE *outputFile = fopen("decrypted.bin", "wb");
        if (outputFile == NULL)
        {
            printf("Failed to open file!\n");
            return;
        }

        size_t keyLength = strlen(key);
        size_t keyIndex = 0;
        unsigned char buffer;

        // Read the file byte by byte.
        while (fread(&buffer, sizeof(unsigned char), 1, inputFile))
        {
            // XOR the buffer with the key byte.
            buffer ^= key[keyIndex % keyLength];
            keyIndex++;

            // Write the encrypted byte to the output file.
            fwrite(&buffer, sizeof(unsigned char), 1, outputFile);
        }

        // Close the files.
        fclose(inputFile);
        fclose(outputFile);

        printf("File decryption completed!\n");
    }
}

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

        // Prompt the user for an encryption key.
        printf("\nEnter an encryption key of your choice: \n");
        printf("=============================================\n");
        scanf("%s", &key);

        // Call the Encryption function.
        xorEncryptFile(path, key);
    }
    else if (task == 2)
    {
        printf("Enter the file path of the file you want to decrypt:\n");
        printf("====================================================\n");
        scanf("%s", &path);

        // Prompt the user for the decryption key.
        printf("\nEnter the decryption key of the file: \n");
        printf("=============================================\n");
        scanf("%s", &key);

        // Call the Decryption function.
        xorDecryptFile(path, key);
    }
    else
    {
        printf("Invalid input!");
        return 1;
    }

    return 0;
}