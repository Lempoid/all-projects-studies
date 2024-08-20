/*
Alex Breger
Reviewed: Ben Bortkevich 19.8.24
*/

#include <stdio.h> /*printf*/
long Pow2(unsigned int x, unsigned int y);

int main()
{
	int x = 6;
	int y = 2;
	printf("%d", x);
	x = Pow2(x,y);
	printf("%d", x);
	return 0;
}

long Pow2(unsigned int x, unsigned int y)
{
	return x << y;	
}