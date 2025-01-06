#include "server2.h"
#include "tun.h"

void set_up_route_to_internet()
{
    char shell_command[1024];

    //system("sudo ip addr flush dev tun0");
    //system("sudo ip route flush dev tun0");
    system("sudo ip route add 10.0.0.0/24 dev tun0");
    system("echo 1 > /proc/sys/net/ipv4/ip_forward");
    system("sudo iptables -F");
    system("sudo iptables -t nat -F");
    system("sudo iptables -t nat -A POSTROUTING -o wlo1 -j MASQUERADE");
    system("sudo iptables -A FORWARD -i tun0 -o wlo1 -j ACCEPT");
    system("sudo iptables -A FORWARD -i wlo1 -o tun0 -j ACCEPT");
}

void run_server()
{
    int server_fd;
    struct sockaddr_in address, client_address;
    socklen_t addr_len;
    char buffer[BUFFER_READ_SIZE];
    int tun_fd;
    ssize_t bytes_received;

    char tun_name[IFNAMSIZ] = "tun0";
    tun_fd = tun_alloc(tun_name, IFF_TUN | IFF_NO_PI);
    if (tun_fd < 0)
    {
        fprintf(stderr, "Failed to create TUN device\n");
        return;
    }
    if (setup_tun_interface(tun_name, "10.0.0.1", "24") < 0)
    {
        close(tun_fd);
        return;
    }
    printf("TUN device %s set up successfully\n", tun_name);

    set_up_route_to_internet();

    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd < 0)
    {
        fprintf(stderr, "Couldn't create server socket\n");
        tear_down_tun_interface(tun_name);
        close(tun_fd);
        return;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = inet_addr("192.168.57.1");

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        fprintf(stderr, "Couldn't bind\n");
        tear_down_tun_interface(tun_name);
        close(tun_fd);
        close(server_fd);
        return;
    }

    addr_len = sizeof(client_address);

    while (1)
    {
        bytes_received = recvfrom(server_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_address, &addr_len);
        if (bytes_received > 0)
        {
            write(tun_fd, buffer, bytes_received);
        }

        ssize_t nread = read(tun_fd, buffer, sizeof(buffer));
        if (nread > 0)
        {
            sendto(server_fd, buffer, nread, 0, (struct sockaddr *)&client_address, addr_len);
        }
    }

    tear_down_tun_interface(tun_name);
    close(tun_fd);
    close(server_fd);
}
