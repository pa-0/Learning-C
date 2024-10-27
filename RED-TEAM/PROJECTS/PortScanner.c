/*
SIMPLE PORT SCANNER PROGRAM BY DANTECHOPPAXXX.
==============================================
This program scans a specific range of ports on a target IP or hostname to determine which ports are open, closed, or filtered, then saves the results in a txt file.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/time.h>

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

// Fucntion to scan port on target host.
int scanPort(const char *ip, unsigned long port, int timeout_seconds)
{
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Socket creation failed");
        return -1;
    }

    // Set up the timeout structure
    struct timeval timeout;
    timeout.tv_sec = timeout_seconds;
    timeout.tv_usec = 0;

    // Apply the timeout to the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) < 0)
    {
        perror("Failed to set socket send timeout");
        close(sockfd);
        return -1;
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0)
    {
        perror("Failed to set socket receive timeout");
        close(sockfd);
        return -1;
    }

    // Set up server address structure.
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons((unsigned short)port);
    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0)
    {
        perror("Invalid IP address!");
        close(sockfd);
        return -1;
    }

    // Attempt to connect to the server.
    int connection_result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Interpret the conection result.
    if (connection_result == 0)
    {
        printf("Port %lu is OPEN on %s\n", port, ip);
        close(sockfd);
        return 0;
    }
    else if (errno == ECONNREFUSED)
    {
        printf("Port %lu is CLOSED on %s\n", port, ip);
    }
    else if (errno == ETIMEDOUT)
    {
        printf("Port %lu is FILTERED (timed out) on %s\n", port, ip);
    }
    else
    {
        printf("Error occurred: %s\n", strerror(errno));
    }

    close(sockfd);
    return -1;
}

void writeResult(FILE *file, unsigned long port, const char *status, const char *host)
{
    fprintf(file, "Port %lu is %s on %s\n", port, status, host);
}

int main()
{

    char targetHost[100];
    char *pTargetHost = targetHost; // Pointer to target IP.
    int start, end;                 // Port range.
    int timeout = 3;

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

    // Open file for writing.
    FILE *file = fopen("ScanResults.txt", "w");
    if (file == NULL)
    {
        perror("Failed to open file!");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        /* Perform port scan. */
        int scanResult = scanPort(pTargetHost, pPortList[i], timeout);
        if (scanResult == 0)
        {
            writeResult(file, pPortList[i], "OPEN", pTargetHost);
        }
        else if (scanResult == -1)
        {
            writeResult(file, pPortList[i], "CLOSED", pTargetHost);
        }
        else
        {
            writeResult(file, pPortList[i], "FILTERED", pTargetHost);
        }
    }

    fclose(file);
    printf("========================================\n");
    printf("Scan results written to ScanResults.txt\n");
    printf("========================================\n");

    return 0;
}
