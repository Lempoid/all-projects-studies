/*
Alex Breger
Reviewed: Chananya Templeman 6.10.24
*/

#include <stdio.h> /*printf*/
#include <time.h> /*srand time*/
#include <stdlib.h> /*malloc*/
#include "cyber-ds-sorts_ex7.h"

#define ARRAY_SIZE 5000
int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() 
{
    srand(time(NULL));
    int* array = (int*)malloc(ARRAY_SIZE * sizeof(int));
    size_t i;
    size_t nmemb = ARRAY_SIZE;

    
    for (i = 0; i < ARRAY_SIZE; ++i)
    {
        array[i] = rand() % 100;
    }
    
    RecursiveQsort(array, nmemb, sizeof(int), compare_ints);

    for (i = 0; i < ARRAY_SIZE; ++i)
    {
        printf("%d ", array[i]);
        if(0 == i % 10)
        {
            printf("\n"); 
        }
        if (array[i] < array[i-1]) 
        {
        printf("Array not sorted at index %zu\n", i);
        break;
    }
    }
    
    return 0;
}