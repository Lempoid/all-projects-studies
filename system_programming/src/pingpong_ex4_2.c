#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void handler(int sig)
{
    if (SIGUSR1 == sig)
    {
        printf("Recieved signal\n");
    }
}

int main(char *argc, char *argv[])
{
    pid_t pid = atoi(argv[1]);
    printf("Sending signal to the waiting process\n");
    signal(SIGUSR1,handler);


    kill(pid, SIGUSR1);


    printf("And now I am waiting.\n");
    pause();
    printf("I am back!\n");
    return 0;
}
