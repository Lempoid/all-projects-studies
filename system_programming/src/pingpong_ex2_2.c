#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void handler()
{
    printf("Parent accepted handler.\n");
}


int main()
{
    
    printf("In executable 2\n");

    signal(SIGUSR1,handler);

    kill(getppid(),SIGUSR1);

    return 0;
}
