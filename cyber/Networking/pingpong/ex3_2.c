/*
Reviewed: Ben Bortkevich
Author: Alex Breger
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[256], client_message[256];

    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if(0 > socket_desc)
    {
        printf("Failed to open socket.\n");
        return -1;
    }

    printf("Socket created successfully.\n");

    server_addr.sin_addr.s_addr = inet_addr("10.10.1.84");
    server_addr.sin_port = htons(15000);
    server_addr.sin_family = AF_INET;

    if(0 > connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)))
    {
        printf("Was unable to connect to server.\n");
        return -1;
    }

    printf("Connected with server succesfully.\n");

    printf("Enter message: \n");
    scanf("%255s", client_message);

    if(0 > send(socket_desc, client_message, sizeof(client_message), 0))
    {
        printf("Was unable to send message to server");
        return -1;
    }

    if(0 > recv(socket_desc, server_message, sizeof(server_message), 0))
    {
        printf("Failed to recieve a message from the server.\n");
        return -1;
    }

    printf("Server responded with %s", server_message);

    close(socket_desc);

    return 0;

}