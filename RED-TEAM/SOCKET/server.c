#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/time.h>

int main()
{

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    return 0;
}