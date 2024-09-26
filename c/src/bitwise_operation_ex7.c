/*
Alex Breger
Reviewed: Ben Bortkevich 19.8.24
*/

#include <stdio.h> /*printf*/

unsigned int Div16(unsigned int x);

int main()
{
	printf("%u\n", Div16(33));
	return 0;
}

unsigned int Div16(unsigned int x)
{
	    return (x & ~0xF);
}