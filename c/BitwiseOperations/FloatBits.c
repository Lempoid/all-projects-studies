/*
Alex Breger
Reviewed: Ben Bortkevich 19.8.24
*/

#include <stdio.h> /*printf*/

int main()
{
	float x = 8.6;
	int i = 0;
	unsigned int* p = (unsigned int*) &x;
    for (i = 31; i >= 0; i--) 
    {
        printf("%u", (*p >> i) & 1);
    }

    printf("\n");

	return 0;
}