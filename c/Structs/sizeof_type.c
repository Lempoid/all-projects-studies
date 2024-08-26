/*
Alex Breger
Reviewed by: Chananya Tampleman
*/

#include <stdio.h> 

#define SIZEOF_TYPE(a) ((size_t)((char*)(((a*)0 + 1)) - (char*)((a*)0)))

int main()
{
	int x;
	printf("%lu\n", SIZEOF_TYPE(int));
	return 0;
}