#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024 // Process file in chunks to handle larger files

// Function to XOR encrypt/decrypt the file
void xorProcessFile(const char *inputPath, const char *outputPath, const char *key)
{
    FILE *inputFile = fopen(inputPath, "rb");
    if (inputFile == NULL)
    {
        printf("Failed to open input file! (Hint: Make sure the file exists)\n");
        return;
    }

    FILE *outputFile = fopen(outputPath, "wb");
    if (outputFile == NULL)
    {
        printf("Failed to open output file!\n");
        fclose(inputFile);
        return;
    }

    size_t keyLength = strlen(key);
    size_t keyIndex = 0;
    unsigned char buffer[CHUNK_SIZE]; // Buffer to read the file in chunks
    size_t bytesRead;

    // Process the file chunk by chunk
    while ((bytesRead = fread(buffer, sizeof(unsigned char), CHUNK_SIZE, inputFile)) > 0)
    {
        // XOR each byte with the corresponding key byte
        for (size_t i = 0; i < bytesRead; i++)
        {
            buffer[i] ^= key[keyIndex % keyLength];
            keyIndex++;
        }

        // Write the XORed bytes to the output file
        fwrite(buffer, sizeof(unsigned char), bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File processing (encryption/decryption) completed!\n");
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

    // Validate the user input
    if (task != 1 && task != 2)
    {
        printf("Invalid input! Exiting.\n");
        return 1;
    }

    printf("Enter the file path of the file:\n");
    scanf("%s", path); // Assuming the path will fit into 255 characters

    // Get the key from the user
    printf("\nEnter the key (up to 254 characters):\n");
    scanf("%s", key);

    // Perform the task based on user input
    if (task == 1)
    {
        xorProcessFile(path, "encrypted.bin", key);
    }
    else if (task == 2)
    {
        xorProcessFile(path, "decrypted.bin", key);
    }

    return 0;
}
