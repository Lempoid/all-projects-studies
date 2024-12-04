/*
Reviewed: Ben Bortkevich
Author: Alex Breger
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void* client_handle(void *client_socket)
{
    char client_message[256], server_message[256];
    int sock = *(int *)client_socket;
    free(client_socket);


    memset(client_message, '\0', sizeof(client_message));
    memset(server_message, '\0', sizeof(server_message));

    if (0 > recv(sock, client_message, sizeof(client_message), 0))
    {
        printf("Failed to to recieve message from client\n");
        return NULL;
    }

    printf("Message from client: %s\n", client_message);

    strcpy(server_message, "Server accepted your message, this is the response.");

    if (0 > send(sock, server_message, strlen(server_message), 0))
    {
        printf("Failed to respond to send message to client.\n");
        return NULL;
    }

    close(sock);

    return NULL;
}

int main()
{
    int socket_desc, client_sock, *thread_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_size = sizeof(client_addr);

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (0 > socket_desc)
    {
        printf("Failed to create socket.\n");
        return -1;
    }

    printf("Socket is created.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("10.10.2.60");
    server_addr.sin_port = htons(2000);

    if (0 > bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        printf("Failed to bind socket to port.\n");
        return -1;
    }

    printf("Done with binding.\n");

    if (0 > listen(socket_desc, 1))
    {
        printf("Socket failed to listen.\n");
        return -1;
    }

    printf("Socket is listening.\n");

    while ((client_sock = accept(socket_desc, (struct sockaddr *)&client_addr, &client_size)) > 0)
    {
        pthread_t client_thread;
        printf("Client connected from IP: %s and port: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        thread_sock = malloc(sizeof(int));
        
        if(NULL == thread_sock)
        {
            perror("Failed to create thread_sock.\n");
            close(client_sock);
            continue;
        }

        *thread_sock = client_sock;
        if(pthread_create(&client_thread, NULL, client_handle, (void*)thread_sock))
        {
            perror("Failed to create thread.\n");
            close(socket_desc);
            close(client_sock);
            return -1;
        }

        pthread_detach(client_thread);

    }

    if (0 > client_sock)
    {
        printf("Couldn't accept connection from client.\n");
        return -1;
    }

    close(socket_desc);
    close(client_sock);

    return 0;
}