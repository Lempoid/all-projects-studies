#include "stddef.h"
#include "recursion_ex1.h"

int RecursionFibunaci(int n)
{
    if(0 == n)
    {
        return 0;
    }
    else if(1 == n)
    {
        return 1;
    }
    return RecursionFibunaci(n - 1) + RecursionFibunaci(n - 2);
}

int IterativeFibunaci(int n)
{
    size_t next = 1;
    size_t current = 0, previous;
    size_t i;

    for (i = 1; i < n; ++i)
    {
        previous = current;
        current = next;
        next = current + previous;
    }
    
    return next;
}