#include "cyber-ds-sorts_ex7.h"

void RecursiveQsort(void *base, size_t nmemb, size_t size,
int (*compar)(const void *, const void *))
{
    char* pivot = (char*)base + (nmemb / 2) * size;
    char* start = (char*)base;
    char* end = (char*)base + (nmemb - 1) * size;
    size_t i = 0;
    char temp;
    size_t send_left_size;
    size_t send_right_size;

    if(nmemb <= 1)
    {
        return; 
    }

    while(start < end)
    {
        while(start < pivot && compar(start, pivot) <= 0)
        {
            start += size;
        }
        while(end > pivot && compar(end, pivot) > 0)
        {
            end -= size;
        }

        if(start < end)
        {
            for (i = 0; i < size; i++) 
            {
                temp = start[i];
                start[i] = end[i];
                end[i] = temp;
            }
            
            if(start == pivot)
            {
                pivot = end;
            }
            else if(end == pivot)
            {
                pivot = start;
            }
        }
    }

    send_left_size = (pivot - (char*)base) / size;
    send_right_size = nmemb - send_left_size - 1;

    RecursiveQsort(base, send_left_size, size, compar);
    RecursiveQsort(pivot + size, send_right_size, size, compar);
}