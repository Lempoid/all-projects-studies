#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int signal_received = 0;

/*Signal handler function: sets the signal_received flag to 1 when a signal is caught.
  signo is the signal number that triggered this handler. It allows the handler
  to identify which signal was received, enabling the handling of multiple signals
  with the same function if needed.*/
void signal_handler()
{
    signal_received = 1;
}

int main()
{
    pid_t pid;
    int count = 5;

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0)
    {
        while (count--)
        {
            printf("in child before pause\n");
            pause();
            if (signal_received)
            {
                printf("Child: Received SIGUSR1, sending SIGUSR2 to parent\n");
                signal_received = 0;
                kill(getppid(), SIGUSR2);
            }
        }
    }
    else
    {
        while (count--)
        {
            printf("in parent before sleep\n");
            sleep(1);
            printf("Parent: Sending SIGUSR1 to child\n");
            kill(pid, SIGUSR1);
            printf("in parent before pause\n");
            pause();
            if (signal_received)
            {
                printf("Parent: Received SIGUSR2\n");
                signal_received = 0;
            }
        }
    }

    return 0;
}