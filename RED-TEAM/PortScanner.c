#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a list of ports from the specified range.
char portsList(const int start, const int end, unsigned long *portList)
{

    int index = 0;

    for (int i = start; i < end + 1; i++)
    {
        portList[index] = i;
        index++;
    }
}

struct PortStatus
{
    unsigned long port;
    char status[100];
};

int main()
{

    char targetHost[100];
    int start, end;  // Port range.
    int timeout = 5; // Connection timeout.

    struct PortStatus portStatus;

    printf("PORT SCANNER\n");
    printf("=============\n");

    // Ask the user for the target IP Address.
    printf("Enter the target IP Address:\n");
    printf("============================\n");
    scanf("%s", &targetHost);

    // Ask the user for the target IP Address.
    printf("Enter the range of ports to scan:\n");
    printf("============================\n");
    printf("Enter the starting port:\n");
    printf("========================\n");
    scanf("%d", &start);
    printf("Enter the ending port:\n");
    printf("========================\n");
    scanf("%d", &end);

    int size = end - start + 1; // Size of port list.
    unsigned long portList[size];
    unsigned long *pPortList = portList; // Pointer to port list array.

    portsList(start, end, pPortList);

    for (int i = 0; i < size; i++)
    {

        /* Perform port scan. */

        printf("===================\n");
        printf("%s:%ld\n", targetHost, pPortList[i]);
    }
    return 0;
}
