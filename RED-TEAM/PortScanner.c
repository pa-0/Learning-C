#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char targetHost[100];
    int targetPort;
    int timeout = 5;

    printf("PORT SCANNER\n");
    printf("=============\n");

    printf("Enter the target IP Address:\n");
    printf("============================\n");
    scanf("%s", &targetHost);

    printf("Enter the port number:\n");
    printf("============================\n");
    scanf("%d", &targetPort);

    printf("Target => %s:%d\n", targetHost, targetPort);

    return 0;
}