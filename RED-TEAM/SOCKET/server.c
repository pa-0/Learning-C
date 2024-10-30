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
#define MAX_CLIENTS 5

void *clientHandler(void *socket_desc)
{
    int client_socket = *(int *)socket_desc;
    char client_message[2000], server_message[2000], *welcomeMessage;

    welcomeMessage = "Welcome To The ChatRoom!\n ";
    // Display a welcome message and prompt for a username.
    write(client_socket, welcomeMessage, strlen(welcomeMessage));

    // Handle client communication.
    while (1)
    {
        memset(client_message, 0, sizeof(client_message));

        // Receive a message from the client.
        if (recv(client_socket, client_message, sizeof(client_message), 0) < 0)
        {
            perror("Failed to receive client message!\n");
            break;
        }

        printf("Client: %s\n", client_message);

        // // Get a message to send to the client.
        // printf("Server: ");
        // fgets(server_message, sizeof(server_message), stdin);

        // Send the message to the client.
        if (send(client_socket, server_message, strlen(server_message), 0) < 0)
        {
            perror("Failed to send message to the client!");
            break;
        }
    }
    // Close client socket and free memory
    close(client_socket);
    free(socket_desc);
    pthread_exit(NULL);
}

int main()
{

    int server_socket, client_socket, *new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    // char *message;

    // Create server socket.
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        perror("Failed to create socket!\n");
        return -1;
    }

    // Setup the server address structure.
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server IP and port.
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        close(server_socket);
        return 1;
    }
    printf("Server is ready and bound to port %d\n", SERVER_PORT);
    printf("=======================================\n");

    // Listen for incoming connections.
    listen(server_socket, 3);

    printf("Waiting for incoming connections...\n");
    printf("====================================\n");

    // Accept incoming client connections.
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size)))
    {
        printf("Connection Accepted!\n");

        // Allocate memory for new client socket.
        new_socket = malloc(sizeof(int));
        *new_socket = client_socket;

        // Create new thread for the client.
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, clientHandler, (void *)new_socket) < 0)
        {
            perror("Failed to create thread!\n");
            free(new_socket);
            return 1;
        }
    }
    if (client_socket < 0)
    {
        perror("Failed to accept client connection!\n");
        return -1;
    }

    // Close the socket after handling the client
    close(server_socket);

    return 0;
}