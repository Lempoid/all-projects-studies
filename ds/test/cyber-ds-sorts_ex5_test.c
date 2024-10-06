/*
Alex Breger
Reviewed: Chananya Templeman 6.10.24
*/

#include <stdio.h> /*printf*/
#include <time.h> /*srand time*/
#include <stdlib.h> /*malloc*/
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
