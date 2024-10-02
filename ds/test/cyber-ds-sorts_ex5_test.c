#include <stdio.h>

#include <time.h>
#include <stdlib.h>
#include "cyber-ds-sorts_ex5.h"

int main()
{
    srand(time(NULL));
    int* array = (int*)malloc(5000 * sizeof(int));
    size_t i;
    
    for (i = 0; i < 5000; ++i)
    {
        array[i] = rand() % 100;
    }
    
    CountSort(array, 5000);

    for ( i = 0; i < 5000; ++i)
    {
        printf("%d ", array[i]);
        if(0 == i % 10)
        {
            printf("\n"); 
        }
    }
    
    return 0;
}
