#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

void handler()
{
    printf("Child accepted handler.\n");
}


int main()
{

    int pid;

    pid = fork();
    char *args[] = {"./a.out", NULL};

    signal(SIGUSR1,handler);

    if (0 > pid)
    {
        perror("Failed to fork\n");
        return 1;
    }

    
    if (0 == pid)
    {
        printf("Executing new program\n");
        execl(args[0], "a.out",NULL);
    }

    else
    {
        printf("In parent before pause\n");
        kill(pid,SIGUSR1);
        pause();

        printf("Parent got a response, it can continue\n");
    }
    printf("waiting before termination in parent\n");
    sleep(100);
    return 0;
}
