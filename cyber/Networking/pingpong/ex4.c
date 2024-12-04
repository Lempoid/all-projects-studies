/*
Reviewed: Ben Bortkevich
Author: Alex Breger
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main()
{

    int socket_desc;
    struct sockaddr_in server_address;
    char broadcast_message[256];
    socklen_t server_struct_length = sizeof(server_address);
    int broadcast_enable = 1;


    memset(broadcast_message, '\0', sizeof(broadcast_message));

    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if(0 > socket_desc)
    {
        printf("Failed to create socket.\n");
        return -1;
    }

    if(0 > setsockopt(socket_desc, SOL_SOCKET, SO_BROADCAST, &broadcast_enable, sizeof(broadcast_enable)))
    {
        perror("Failed to enable broadcast.\n");
        close(socket_desc);
        return -1;
    }

    server_address.sin_addr.s_addr = inet_addr("10.10.3.255");
    server_address.sin_port = htons(2000);
    server_address.sin_family = AF_INET;

    printf("Enter a message\n");
    fgets(broadcast_message, sizeof(broadcast_message), stdin);
    


    if(0 > sendto(socket_desc, broadcast_message, strlen(broadcast_message),0 ,(struct sockaddr*)&server_address, server_struct_length))
    {
        perror("Error: ");
        printf("Failed to send message.\n");
        close(socket_desc);
        return -1;
    }

    close(socket_desc);

    return 0;
}