#include <stdio.h>
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

/*x*(2^y)*/
long Pow2(unsigned int x, unsigned int y)
{
	return x << y;	
}