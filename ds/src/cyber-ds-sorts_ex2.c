/*
Alex Breger
Reviewed: Chananya Templeman 6.10.24
*/

#include "cyber-ds-sorts_ex2.h"

void MyBubbleSort(int* array, size_t size)
{
    size_t i;
    size_t j;
    int tmp;

    for(i = 0; i < size - 1; ++i)
    {
        for (j = 0; j < size - i - 1; ++j)
        {
            if(array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
        
    }
}