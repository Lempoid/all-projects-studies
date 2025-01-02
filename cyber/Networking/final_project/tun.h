#ifndef __TUN_H__
#define __TUN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/if.h>
#include <linux/if_tun.h>

#define BUFFER_READ_SIZE 1500

int tun_alloc(char *device_name, int flags);
int setup_tun_interface(char *device_name, char *ip, char *netmask);
int tear_down_tun_interface(char *device_name);

#endif /*TUN_H*/ 
