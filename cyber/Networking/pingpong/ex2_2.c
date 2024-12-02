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
    socklen_t server_struct_length = sizeof(server_addr);

    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if(0 > socket_desc)
    {
        printf("Error while creating socket.\n");
        return -1;
    }
    printf("Client socket created successfully.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter message:\n");
    scanf("%255s", client_message);

    if(0 > sendto(socket_desc, client_message, strlen(client_message), 0, (struct sockaddr*)&server_addr, server_struct_length))
    {
        printf("Failed to send message.\n");
        return -1;
    }

    if(0 > recvfrom(socket_desc, server_message, sizeof(server_message), 0, (struct sockaddr*)&server_addr, &server_struct_length))
    {
        printf("Error while recieiving server's message.\n");
        return -1;
    }

    printf("Recieved message from IP: %s and port: %i\n", inet_ntoa(server_addr.sin_addr), htons(server_addr.sin_port));
    
    printf("Server response: %s", server_message);

    close(socket_desc);

    return 0;
}
