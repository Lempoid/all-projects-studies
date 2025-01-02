#ifndef __SERVER_2_H__
#define __SERVER_2_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5000
#define BUFFER_SIZE 1024

void run_server();
void set_up_route_to_internet();

#endif /*SERVER_2_H*/