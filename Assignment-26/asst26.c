#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* bind shell */

#define PORT 5555

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    printf("Socket created.\n");

    // declare members of server socket address
    /*struct sockaddr_in { // internet socket address
        short            sin_family;   // e.g. AF_INET
        unsigned short   sin_port;     // e.g. htons(3490)
        struct in_addr   sin_addr;     // see struct in_addr, below
        char             sin_zero[8];  // zero this if you want to
    };

    struct in_addr { // internet address
        unsigned long s_addr;  // load with inet_aton()
    };*/
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // bind to all local interfaces
    server_addr.sin_port = htons(PORT);

    // bind socket to address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket to address");
        exit(1);
    }

    printf("Socket bound to internet address.\n");

    return 0;
}