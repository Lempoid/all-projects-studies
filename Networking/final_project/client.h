#ifndef __CLIENT_H__
#define __CLIENT_H__

int run_shell_cmd(char* command);
int open_tun(char* device_name);
void close_tun();
void setup_route_table();
void cleanup_route_table();
int udp_bind();
void clean_up();
void cleanup_when_sig_exit();
static int max(int a, int b);

#endif /*CLIENT_H*/