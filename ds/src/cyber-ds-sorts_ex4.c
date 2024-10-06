#include "cyber-ds-sorts_ex4.h"

void InsertionSort(int* array, size_t size)
{
    size_t i;
    size_t j;
    int element;
    for(i = 1; i < size; ++i)
    {
        element = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > element)
        {
            array[j + 1] = array[j];
            j = j- 1;
        }
        array[j +   1] = element;
    }
}