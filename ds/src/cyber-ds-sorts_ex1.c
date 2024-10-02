#include "/home/lempo/git/ds/include/cyber-ds-sorts_ex1.h"

int RecursiveBinarySearch(int* array, size_t start, size_t end, int to_find)
{
    size_t mid = start + (end - start) / 2;
    if(start > end)
    {
        return -1;
    }

    if(array[mid] == to_find)
    {
        return mid;
    }
    else if(array[mid] > to_find)
    {
        RecursiveBinarySearch(array, start, mid - 1, to_find);
    }
    else
    {
        RecursiveBinarySearch(array, start + 1, end, to_find);
    }

}

int IterativeBinarySearch(int* array, size_t size, int to_find)
{
    size_t mid;
    size_t start = 0;
    size_t end = size - 1;

    while(start < end)
    {
        mid = start + (end - start) / 2;
        if(array[mid] == to_find)
        {
            return mid;
        }
        else if(array[mid] > to_find)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}