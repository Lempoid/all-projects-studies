#include "cyber-ds-sorts_ex3.h"

void SelectionSort(int* array, size_t size)
{
    size_t i = 0;
    size_t j = 0;
    int min;
    int tmp;

    for(i = 0; i < size - 1; ++i)
    {
        min = i;
        for(j = i + 1; j < size; ++j)
        {
            if(array[j] < array[min])
            {
                min = j;
            }
        }

        if(min != i)
        {
            tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }
}