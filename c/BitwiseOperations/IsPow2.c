/*
Alex Breger
Reviewed: Ben Bortkevich 19.8.24
*/

#include <stdio.h> /*printf*/

unsigned int IsPow2(unsigned int x);
unsigned int IsPow2Loop(unsigned int x);

int main()
{
	
	int x = 6;
	printf("%d\n", IsPow2(x));
	printf("%d\n", IsPow2Loop(x));
	return 0;
}


unsigned int IsPow2(unsigned int x)
{
	return (x == (x & -x));
}

unsigned int IsPow2Loop(unsigned int x)
{
	unsigned int y = 1;
	while(y < x)
	{
		y = y << 1;
		
		if(x == y)
		{
			return 1;
		}
	}
	return 0;

}