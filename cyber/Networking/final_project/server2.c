#include "server2.h"
#include "tun.h"

void run_server()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t addr_len;
    char buffer[BUFFER_READ_SIZE];
    int tun_fd;
    size_t bytes_received;
    char tun_name[IFNAMSIZ] = "tun0";

    if (0 > (tun_fd = tun_alloc(tun_name, IFF_TUN | IFF_NO_PI)))
    {
        fprintf(stderr, "Failed to create TUN device\n");
        return;
    }
    if (0 > setup_tun_interface(tun_name, "10.0.0.1", "24"))
    {
        close(tun_fd);
        return;
    }
    printf("TUN device %s set up successfully\n", tun_name);

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = inet_addr("192.168.57.1");

    if (0 > (server_fd = socket(AF_INET, SOCK_STREAM, 0)))
    {
        fprintf(stderr, "Couldn't create server socket\n");
        tear_down_tun_interface(tun_name);
        close(tun_fd);
        return;
    }

    if (0 > bind(server_fd, (struct sockaddr *)&address, sizeof(address)))
    {
        fprintf(stderr, "Couldn't bind\n");
        tear_down_tun_interface(tun_name);
        close(tun_fd);
        close(server_fd);
        return;
    }

    listen(server_fd, 1);

    addr_len = sizeof(address);

    new_socket = accept(server_fd, (struct sockaddr *)&address, &addr_len);

    while (1)
    {
        int nread;

        if (0 < (bytes_received = recv(new_socket, buffer, sizeof(buffer), 0)))
        {
            write(tun_fd, buffer, bytes_received);
        }

        if (0 < (nread = read(tun_fd, buffer, sizeof(buffer))))
        {
            send(new_socket, buffer, nread, 0);
        }
    }

    tear_down_tun_interface(tun_name);
    close(tun_fd);
    close(new_socket);
    close(server_fd);
}
