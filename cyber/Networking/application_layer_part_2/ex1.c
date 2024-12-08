#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFERSIZE 65536

void web(int fd)
{
    int j, file_fd;
    long i, ret;
    static char buffer[BUFFERSIZE * 2];

    ret = read(fd, buffer, BUFFERSIZE);
    if (0 >= ret)
    {
        perror("Failed to read from buffer.\n");
    }

    if (0 < ret && ret < BUFFERSIZE)
    {
        buffer[ret] = 0;
    }
    else
    {
        buffer[0] = 0;
    }

    for (i = 0; i < ret; ++i)
    {
        if (buffer[i] == '\r' || buffer[i] == '\n')
        {
            buffer[i] = '*';
        }
    }

    if (strncmp(buffer, "GET", 4) && strncmp(buffer, "get", 4))
    {
        perror("Only simple GET operations are allowed");
    }

    for (i = 4; i < BUFFERSIZE; ++i)
    {
        if (buffer[i] == ' ')
        {
            buffer[i] = 0;
            break;
        }
    }

    for (j = 0; j < i - 1; j++)
    {
        if (buffer[j] == '.' && buffer[j + 1] == '.')
        {
            perror("Forbidden parent dir.\n");
        }
    }

    if(!strncmp(&buffer[0], "GET /\0", 6) || !strncmp(&buffer[0],"get /\0",6))
    {
        strcpy(buffer,"GET /index.html");
    }

    
    if(-1 == (file_fd = open(&buffer[5], O_RDONLY)))
    {
        perror("Couldn't open file for reading.\n");
    }

    lseek(file_fd, (off_t)0, SEEK_SET);

    sprintf(buffer,"HTTP/1.1 200 OK");
    write(fd,buffer,strlen(buffer));

    while(0 < (ret = read(file_fd,buffer,BUFFERSIZE)))
    {
        write(fd,buffer,ret);
    }

    sleep(1);
    close(fd);
}

int main()
{
    int port, listenfd, socketfd;
    socklen_t length;
    static struct sockaddr_in cli_addr;
    static struct sockaddr_in serv_addr;

    if (0 > (listenfd = socket(AF_INET, SOCK_STREAM, 0)))
    {
        perror("Can't create socket: listenfd.\n");
        return -1;
    }
    chroot("lempo");
    port = 8000;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    if (0 > bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)))
    {
        perror("Couldn't bind listenfd.\n");
        return -1;
    }

    if (0 > listen(listenfd, 64))
    {
        perror("Listening on listenfd failed.\n");
        return -1;
    }
    length = sizeof(cli_addr);

    if (0 > (socketfd = accept(listenfd, (struct sockaddr *)&cli_addr, &length)))
    {
        perror("Failed to accept connection on listenfd.\n");
        return -1;
    }

    web(socketfd);

    return 0;
}