#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int socket_desc;
    struct sockaddr_in server_addr, client_addr;
    char server_message[256], client_message[256];
    socklen_t client_struct_length = sizeof(client_addr);

    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));


    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if(socket_desc < 0)
    {
        printf("Error while creating socket\n");
        return - 1;
    }
    printf("Socket created.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(0 > bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)))
    {
        printf("Couldn't bind to the port.\n");
        return -1;
    }

    printf("Done with binding.\n");
    printf("Listeneing for incoming messages\n");

    if( 0 > recvfrom(socket_desc, client_message, sizeof(client_message), 0, (struct sockaddr*)&client_addr, &client_struct_length))
    {
        printf("Couldn't recieve.\n");
        return -1;
    }

    printf("Recieved message from IP: %s and port: %i\n", inet_ntoa(client_addr.sin_addr), htons(client_addr.sin_port));

    printf("Message from client: %s\n", client_message);

    strcpy(server_message, client_message);

    if(0 > sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr, client_struct_length))
    {
        printf("Can't send.\n");
        return -1;
    }

    close(socket_desc)
    return 0;
}
