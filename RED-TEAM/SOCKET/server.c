#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/time.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6302

int main()
{

    int sockfd, client_socket, c;
    struct sockaddr_in server_addr, client_addr;
    char *message;
    char client_message[2000], server_message[2000];

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Failed to create socket!\n");
        return -1;
    }

    // Setup the server address structure.
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server IP and port.
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        return 1;
    }
    printf("Server is ready and bound to port %d\n", SERVER_PORT);
    printf("=======================================\n");

    // Listen for incoming connections.
    listen(sockfd, 3);

    printf("Waiting for incoming connections...\n");
    printf("====================================\n");

    c = sizeof(struct sockaddr_in);

    // Accept incoming client connections.
    client_socket = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&c);
    if (client_socket < 0)
    {
        perror("Failed to accept client connection!\n");
        return -1;
    }

    printf("Connection Accepted!\n");

    while (1)
    {
        // // Send a welcome message to the client.
        // message = "Hello Neo, Welcome to The Matrix!\n";
        // write(client_socket, message, strlen(message));

        memset(client_message, 0, sizeof(client_message));

        // Receive a message from the client.
        if (recv(client_socket, client_message, sizeof(client_message), 0) < 0)
        {
            perror("Failed to receive client message!\n");
            break;
        }

        printf("Client: %s\n", client_message);

        // Get a message to send to the client.
        printf("Server: ");
        fgets(server_message, sizeof(server_message), stdin);

        // Send the message to the client.
        if (send(client_socket, server_message, strlen(server_message), 0) < 0)
        {
            perror("Failed to send message to the client!");
            break;
        }
    }

    // Close the sockets after handling the client
    close(client_socket);
    close(sockfd);

    return 0;
}