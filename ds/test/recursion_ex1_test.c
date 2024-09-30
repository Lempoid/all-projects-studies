#include <stdio.h>
#include "recursion_ex1.h"

#define NUMER_FOR_FIBUNACI 5
int main()
{
    
    printf("Recursion fibunaci for %d is %d\n", NUMER_FOR_FIBUNACI, RecursionFibunaci(NUMER_FOR_FIBUNACI));
    printf("Iterative fibunaci for %d is %d\n", NUMER_FOR_FIBUNACI, IterativeFibunaci(NUMER_FOR_FIBUNACI));
    
    return 0;
}
