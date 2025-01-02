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

    if ((client_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        fprintf(stderr, "Couldn't create client socket\n");
        tear_down_tun_interface(tun_name);
        close(tun_fd);
        return;
    }

    system("sudo ip addr flush dev tun0");
    system("sudo ip route flush dev tun0");
    system("sudo ip route add 10.0.0.0/24 dev tun0");
    system("sudo ip route add 192.168.57.1 via 192.168.57.1 dev enp0s3");
    system("sudo ip route add default dev tun0");
    
    system("sysctl -w net.ipv4.ip_forward=1");
    system("iptables -t nat -A POSTROUTING -o tun0 -j MASQUERADE");

    system("iptables -I FORWARD 1 -i tun0 -m state --state RELATED,ESTABLISHED -j ACCEPT");
    system("iptables -I FORWARD 1 -o tun0 -j ACCEPT");
    

    while (1)
    {
        socklen_t addr_len;
        int nread = read(tun_fd, buffer, sizeof(buffer));
        if (nread > 0)
        {
            sendto(client_fd, buffer, nread, 0, (struct sockaddr *)&server_address, sizeof(server_address));
        }

        addr_len = sizeof(server_address);
        bytes_received = recvfrom(client_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&server_address, &addr_len);
        if (bytes_received > 0)
        {
            write(tun_fd, buffer, bytes_received);
        }
    }

    tear_down_tun_interface(tun_name);
    close(tun_fd);
    close(client_fd);
}
