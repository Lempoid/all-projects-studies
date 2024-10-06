/*
Alex Breger
Reviewed: Chananya Templeman 6.10.24
*/

#include <stdio.h> /*printf*/
#include "cyber-ds-sorts_ex1.h"

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};

    printf("recursive binary: %d\n",RecursiveBinarySearch(array,0 , 10, 5));
    printf("itirative binary: %d\n",IterativeBinarySearch(array, 10, 5));

    return 0;
}