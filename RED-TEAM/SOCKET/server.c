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
#define USERNAME_SIZE 256

typedef struct
{
    int client_socket;
    char *username;
} ClientArgs;

void *clientHandler(void *args)
{
    ClientArgs *client_args = (ClientArgs *)args;
    int client_socket = client_args->client_socket;
    char *username = client_args->username;
    char client_message[2000], server_message[2000], *welcomeMessage;

    welcomeMessage = "WELCOME TO THE CHAT ROOM\n==========================\n";
    // Display a welcome message and prompt for a username.
    send(client_socket, welcomeMessage, strlen(welcomeMessage), 0);

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

        printf("%s #=> %s\n", username, client_message);

        // Get a message to send to the client.
        printf("Server #=> ");
        fgets(server_message, sizeof(server_message), stdin);

        // Send the message to the client.
        if (send(client_socket, server_message, strlen(server_message), 0) < 0)
        {
            perror("Failed to send message to the client!");
            break;
        }
    }
    // Close client socket and free memory
    close(client_socket);
    free(client_args);
    pthread_exit(NULL);
}

int main()
{

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    // char *message;
    char *username = malloc(USERNAME_SIZE);
    if (username == NULL)
    {
        perror("Memory allocation failed");
        exit(1);
    }

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
        printf("=====================\n");

        // // Allocate memory for new client socket.
        // new_socket = malloc(sizeof(int));
        // *new_socket = client_socket;

        // Receive data into 'username' buffer.
        int bytes_received = recv(client_socket, username, USERNAME_SIZE - 1, 0);
        if (bytes_received < 0)
        {
            perror("Received Failed!\n");
        }
        else
        {
            // Null-terminate the received string.
            username[bytes_received] = '\0';
            printf("Received username: %s\n", username);
            printf("====================================\n");
        }

        // Free allocated memory when done.
        // free(username);

        // Allocate and initialize arguments struct.
        ClientArgs *client_args = malloc(sizeof(ClientArgs));
        if (client_args == NULL)
        {
            perror("Memory allocation failed");
            continue;
        }

        client_args->client_socket = client_socket;
        client_args->username = username;

        // printf("%s\n", username);

        // Create new thread for the client.
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, clientHandler, (void *)client_args) < 0)
        {
            perror("Failed to create thread!\n");
            free(client_args);
            return 1;
        }

        pthread_detach(client_thread);
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
