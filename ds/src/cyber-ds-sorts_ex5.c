#include <stdlib.h>
#include "cyber-ds-sorts_ex5.h"

void CountSort(int* array, size_t size)
{
    int max = array[0];
    size_t i = 0;
    int* countingArray;
    int* sumArray;

    for(i = 0; i < size; ++i)
    {
        if(max < array[i])
        {
            max = array[i];
        }
    }

    countingArray = calloc(max + 1, sizeof(int));

    for(i = 0; i < max + 1; ++i)
    {
        countingArray[array[i]] += 1;
    }

    for(i = 1; i < max + 1; ++i)
    {
        countingArray[i] = countingArray[i - 1] + countingArray[i];
    }

    sumArray = (int*)malloc(size * sizeof(int));

    for(i = size - 1; i >= 0; --i)
    {
        sumArray[countingArray[array[i] - 1]] = array[i];
        countingArray[array[i]] = countingArray[array[i]] - 1;
    }

    for (i = 0; i < size; ++i)
    {
        array[i] = sumArray[i];
    }

    free(sumArray);
    free(countingArray);

    sumArray = NULL;
    countingArray = NULL;    
}
