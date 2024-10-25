#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a list of ports from the specified range.
char portsList(const int start, const int end, char *portList)
{

    int index = 0;

    for (int i = start; i < end + 1; i++)
    {
        portList[index] = i;
        index++;
    }
}

int main()
{

    char targetHost[100];
    int start, end;             // Port range.
    int size = end - start + 1; // Size of port list.
    char portList[size];
    char *pPortList = portList; // Pointer to port list array.
    int timeout = 5;            // Connection timeout.

    printf("PORT SCANNER\n");
    printf("=============\n");

    // Ask the user for the target IP Address.
    printf("Enter the target IP Address:\n");
    printf("============================\n");
    scanf("%s", &targetHost);

    // Ask the user for the target IP Address.
    printf("Enter the port number:\n");
    printf("============================\n");
    scanf("%d", &targetPort);

    printf("Target => %s:%d\n", targetHost, targetPort);
    portsList(start, end, pPortList);

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", portList[i]);
    }
    return 0;
}