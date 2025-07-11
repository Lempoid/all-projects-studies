// Receive encapsulated packets over a socket.
// Decrypt and extract the inner packet.
// Use raw sockets to forward the inner packet to its destination.
// Capture replies, encrypt them, and send them back to the client.

// Create a TUN device to intercept traffic.
// Encrypt and encapsulate intercepted packets.
// Send the encapsulated packet to the VPN server over a socket (UDP or TCP).

#include <stdlib.h>    /*system*/
#include <fcntl.h>     /*O_RDWR*/
#include <stdlib.h>    /* malloc free */
#include <string.h>    /* memset memcpy */
#include <sys/ioctl.h> /* ioctl */
#include <unistd.h>    /* read close*/
#include <stdio.h>     /* perror */
#include <signal.h>

/*for struct ifreq, etc*/
#include <linux/if.h>
#include <linux/if_tun.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netdb.h>

#include "server.h" /* run_shell_cmd */

#define BUFFER_SIZE 1600
#define PORT 54345
#define MTU 1400
#define BIND_HOST "0.0.0.0"

static int max(int a, int b)
{
    return a > b ? a : b;
}

int run_shell_cmd(char *command)
{
    int status;
    status = system(command);
    if (0 != status)
    {
        perror("Failed to execute shell command.\n");
        return 1;
    }

    return status;
}

int open_tun(char *device_name)
{
    struct ifreq ifr;
    int fd, err;

    run_shell_cmd("sudo ip tuntap add mode tun dev tun0");
    run_shell_cmd("sudo ip addr add 10.10.3.1/24 dev tun0");
    run_shell_cmd("sudo ip link set dev tun0 up");
    run_shell_cmd("ip route get 10.10.3.50");

    if (-1 == (fd = open("/dev/net/tun", O_RDWR)))
    {
        perror("open /dev/net/tun");
        return 1;
    }

    memset(&ifr, 0, sizeof(ifr));
    ifr.ifr_flags = IFF_TUN | IFF_NO_PI;
    strncpy(ifr.ifr_name, device_name, IFNAMSIZ);

    if (-1 == (err = ioctl(fd, TUNSETIFF, (void *)&ifr)))
    {
        perror("ioctl TUNSETIFF");
        return 1;
        close(fd);
    }

    return fd;
}

void close_tun()
{
    run_shell_cmd("sudo ip link set dev tun0 down");
    run_shell_cmd("sudo ip tuntap del mode tun dev tun0");
}

void setup_route_table()
{
    run_shell_cmd("iptables -t nat -A POSTROUTING -s 10.10.3.0/24 ! -d 10.10.3.0/24 -m comment --comment 'vpndemo' -j MASQUERADE");
    run_shell_cmd("iptables -A FORWARD -s 10.10.3.0/24 -m state --state RELATED,ESTABLISHED -j ACCEPT");
    run_shell_cmd("iptables -A FORWARD -d 10.10.3.0/24 -j ACCEPT");
}

void cleanup_route_table()
{
    run_shell_cmd("iptables -t nat -D POSTROUTING -s 10.10.3.0/24 ! -d 10.10.3.0/24 -m comment --comment 'vpndemo' -j MASQUERADE");
    run_shell_cmd("iptables -D FORWARD -s 10.10.3.0/24 -m state --state RELATED,ESTABLISHED -j ACCEPT");
    run_shell_cmd("iptables -D FORWARD -d 10.10.3.0/24 -j ACCEPT");
}

int udp_bind(struct sockaddr *addr, socklen_t *addrlen)
{
    struct addrinfo hints;
    struct addrinfo *result;
    int sock, flags;
    const char *host;

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;

    host = BIND_HOST;

    if (0 != getaddrinfo(host, NULL, &hints, &result))
    {
        perror("getaddrinfo error");
        return -1;
    }

    if (result->ai_family == AF_INET)
    {
        ((struct sockaddr_in *)result->ai_addr)->sin_port = htons(PORT);
    }
    else
    {
        perror("Not ipv4 address");
        freeaddrinfo(result);
        return -1;
    }

    memcpy(addr, result->ai_addr, result->ai_addrlen);
    *addrlen = result->ai_addrlen;

    if (-1 == (sock = socket(result->ai_family, SOCK_DGRAM, IPPROTO_UDP)))
    {
        perror("Cannot create socket");
        freeaddrinfo(result);
        return -1;
    }

    freeaddrinfo(result);

    flags = fcntl(sock, F_GETFL, 0);
    if (flags != -1)
    {
        if (-1 != fcntl(sock, F_SETFL, flags | O_NONBLOCK))
            return sock;
    }
    perror("fcntl error");

    close(sock);
    return -1;
}

void clean_up(int signo)
{
    if (signo == SIGHUP || signo == SIGINT || signo == SIGTERM)
    {
        cleanup_route_table();
        exit(0);
    }
}

void cleanup_when_sig_exit()
{
    struct sigaction sa;
    sa.sa_handler = &clean_up;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);

    if (sigaction(SIGHUP, &sa, NULL) < 0)
    {
        perror("Cannot handle SIGHUP");
    }
    if (sigaction(SIGINT, &sa, NULL) < 0)
    {
        perror("Cannot handle SIGINT");
    }
    if (sigaction(SIGTERM, &sa, NULL) < 0)
    {
        perror("Cannot handle SIGTERM");
    }
}

int main()
{
    int tun_fd, nbytes;
    char buf[BUFFER_SIZE];

    tun_fd = open_tun("tun0");

    // ifconfig();
    setup_route_table();
    cleanup_when_sig_exit();

    int udp_fd;
    struct sockaddr_storage client_addr;
    socklen_t client_addrlen = sizeof(client_addr);

    if ((udp_fd = udp_bind((struct sockaddr *)&client_addr, &client_addrlen)) < 0)
    {
        return 1;
    }

    char tun_buf[MTU], udp_buf[MTU];
    bzero(tun_buf, MTU);
    bzero(udp_buf, MTU);

    while (1)
    {
        fd_set readset;
        FD_ZERO(&readset);
        FD_SET(tun_fd, &readset);
        FD_SET(udp_fd, &readset);
        int max_fd = max(tun_fd, udp_fd) + 1;

        if (-1 == select(max_fd, &readset, NULL, NULL, NULL))
        {
            perror("select error");
            break;
        }

        int r;
        if (FD_ISSET(tun_fd, &readset))
        {
            r = read(tun_fd, tun_buf, MTU);
            if (r < 0)
            {
                perror("read from tun_fd error");
                break;
            }

            //encrypt(tun_buf, udp_buf, r);
            printf("Writing to UDP %d bytes ...\n", r);

            r = sendto(udp_fd, udp_buf, r, 0, (const struct sockaddr *)&client_addr, client_addrlen);
            if (r < 0)
            {
                perror("sendto udp_fd error");
                break;
            }
        }

        if (FD_ISSET(udp_fd, &readset))
        {
            r = recvfrom(udp_fd, udp_buf, MTU, 0, (struct sockaddr *)&client_addr, &client_addrlen);
            if (r < 0)
            {
                perror("recvfrom udp_fd error");
                break;
            }

            //decrypt(udp_buf, tun_buf, r);
            printf("Writing to tun %d bytes ...\n", r);

            r = write(tun_fd, tun_buf, r);
            if (r < 0)
            {
                perror("write tun_fd error");
                break;
            }
        }
    }

    close(tun_fd);
    close(udp_fd);

    cleanup_route_table();

    close_tun();
    return 0;
}
