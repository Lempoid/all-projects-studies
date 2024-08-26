/*
Alex Breger
Reviewed by: Chananya Tampleman
*/

#include <stdio.h>

#define SIZEOF_VAR(a) ((char*)(a+1) - (char*)(a))

int main()
{
	int x = 5;
	printf("%lu\n", SIZEOF_VAR(&x));
	return 0;
}