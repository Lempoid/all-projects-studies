#include "tun.h"

int tun_alloc(char *device_name, int flags)
{
    int tun_fd;
    struct ifreq ifr;
    char read_from_tun[BUFFER_READ_SIZE];

    if (0 > (tun_fd = open("/dev/net/tun", O_RDWR)))
    {
        perror("Couldn't open tun_fd.\n");
        return -1;
    }

    memset(&ifr, 0, sizeof(ifr));
    ifr.ifr_flags = flags;
    strncpy(ifr.ifr_name, device_name, IFNAMSIZ);

    if (0 > ioctl(tun_fd, TUNSETIFF, (void *)&ifr))
    {
        perror("Can't configure TUN device.\n");
        close(tun_fd);
        return -1;
    }

    memset(read_from_tun, 0, sizeof(read_from_tun));

    strcpy(device_name, ifr.ifr_name);

    return tun_fd;
}

int setup_tun_interface(char *device_name, char *ip, char *netmask)
{
    char shell_command[100];

    snprintf(shell_command, sizeof(shell_command), "ip link set dev %s up", device_name);
    if (0 != system(shell_command))
    {
        fprintf(stderr, "Failed to up TUN\n");
        return -1;
    }

    snprintf(shell_command, sizeof(shell_command), "ip addr add %s/%s dev %s", ip, netmask, device_name);
    if (0 != system(shell_command))
    {
        fprintf(stderr, "Failed to assign IP to TUN dev\n");
        return -1;
    }

    return 0;
}

int tear_down_tun_interface(char *device_name)
{
    char shell_command[100];

    snprintf(shell_command, sizeof(shell_command), "ip link set dev %s down", device_name);
    if (0 != system(shell_command))
    {
        fprintf(stderr, "Failed to tear down TUN dev\n");
        return -1;
    }

    return 0;
}