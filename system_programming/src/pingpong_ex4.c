#define _POSIX_C_SOURCE 199309L

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>


void handler(int sig, siginfo_t *info, void *ctx)
{
    if (SIGUSR1 == sig)
    {
        pid_t pid = info->si_pid;
        printf("handler recieved in paused process.\n");
        kill(pid, SIGUSR1);
    }
}

int main()
{

    struct sigaction sig_action;

    sig_action.sa_flags = SA_SIGINFO;
    sig_action.sa_sigaction = handler;
    sigemptyset(&sig_action.sa_mask);

    sigaction(SIGUSR1,&sig_action,NULL);

    pid_t pid = getpid();
    printf("Pid is %d\n", pid);
    printf("I am going to pasue my self, send a signal if I am needed.\n");
    pause();
    printf("I have unpaused myself.\n");
    return 0;
}
