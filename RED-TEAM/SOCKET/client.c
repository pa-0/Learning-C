#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/time.h>
#include <pthread.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6302

int main()
{

    char username[100];
    int client_socket;
    struct sockaddr_in server_addr;
    char client_message[2000], server_message[2000];

    printf("Choose a username to chat with: ");
    fgets(username, sizeof(username), stdin);

    if (strlen(username) < 3)
    {
        printf("You must enter a username to process!\n");
        return 1;
    }

    // Create the client socket.
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
    {
        perror("Failed to create socket!\n");
        return -1;
    }

    // Setup the server address structure.
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to the server.
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connection Failed!\n");
        return -1;
    }
    printf("Connection Successful!\n");
    // Display welcome message from server.
    recv(client_socket, server_message, sizeof(server_message), 0);

    // char *message;
    // message = "HELLO MATRIX!\n";
    // Communicate with the server.
    while (1)
    {

        // Get a message to send to the server.
        printf("Client: ");
        fgets(client_message, sizeof(client_message), stdin);

        // Send the message to the server.
        if (send(client_socket, client_message, strlen(client_message), 0) < 0)
        {
            perror("Failed to send message to the client!");
            break;
        }

        memset(server_message, 0, sizeof(server_message));

        if (recv(client_socket, server_message, sizeof(server_message), 0) < 0)
        {
            perror("Couldn't receive message from server!\n");
            break;
        }

        printf("Server: %s\n", server_message);
    }

    close(client_socket);

    return 0;
}