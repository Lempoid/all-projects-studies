#include "client2.h"
#include "tun.h"

void run_client()
{
    int client_fd;
    struct sockaddr_in server_address;
    char buffer[BUFFER_READ_SIZE];
    size_t bytes_received;

    char tun_name[IFNAMSIZ] = "tun0";
    int tun_fd = tun_alloc(tun_name, IFF_TUN | IFF_NO_PI);
    if (tun_fd < 0)
    {
        fprintf(stderr, "Failed to create TUN device\n");
        return;
    }
    if (setup_tun_interface(tun_name, "10.0.0.2", "24") != 0)
    {
        close(tun_fd);
        return;
    }
    printf("TUN device %s set up successfully\n", tun_name);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("192.168.57.1");

    if (0 > (client_fd = socket(AF_INET, SOCK_STREAM, 0)))
    {
        fprintf(stderr, "Couldn't create client socket\n");
        tear_down_tun_interface(tun_name);
        close(tun_fd);
        return;
    }

    if (0 > connect(client_fd, (struct sockaddr *)&server_address, sizeof(server_address)))
    {
        fprintf(stderr, "Couldn't connect to server\n");
        tear_down_tun_interface(tun_name);
        close(tun_fd);
        close(client_fd);
        return;
    }

    while (1)
    {
        int nread;

        if (0 < (nread = read(tun_fd, buffer, sizeof(buffer))))
        {
            send(client_fd, buffer, nread, 0);
        }

        if (0 > (bytes_received = recv(client_fd, buffer, sizeof(buffer), 0)))
        {
            write(tun_fd, buffer, (size_t)bytes_received);
        }
    }

    tear_down_tun_interface(tun_name);
    close(tun_fd);
    close(client_fd);
}