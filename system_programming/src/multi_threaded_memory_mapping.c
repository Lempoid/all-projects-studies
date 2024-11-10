/*
An exercise to mapout the memory map of 2 threads.

Don't forget to link -lpthread.

*/
#include <pthread.h> /*pthread_create pthread_join*/
#include <unistd.h>  /*sleep*/
#include <stdio.h>   /*printf*/

__thread int tls_var = 42;

void *thread1_fun()
{
    size_t i;
    size_t count = 100;

    for (i = 0; i < count; i++)
    {
        printf("In thread 1 fun.\n");
    }
}

void *thread2_fun()
{
    size_t i;
    size_t count = 100;

    for (i = 0; i < count; i++)
    {
        printf("In thread 2 fun.\n");
    }
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    int returned_error;

    returned_error = pthread_create(&thread1, NULL, thread1_fun, NULL);
    returned_error = pthread_create(&thread2, NULL, thread2_fun, NULL);

    printf("Waiting for the thread to end...\n");
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Thread ended.\n");

    return 0;
}
