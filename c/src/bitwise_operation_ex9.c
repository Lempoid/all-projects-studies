/*
Alex Breger
Reviewed: Ben Bortkevich 19.8.24
*/

#include <stdio.h> /*printf*/

int CountSetBits(int x);
void CountSetBitsLoop(int x);

int main()
{
	printf("%d\n", CountSetBits(255));
	CountSetBitsLoop(255);
	
	return 0;
}


int CountSetBits(int x)
{
	if(0 == x)
	{
		return x;
	}

	return (CountSetBits(x >> 1) + (x & 1));
}

void CountSetBitsLoop(int x)
{
	int count = 0;

	while(x > 0)
	{
		if(x & 1)
		{
			++count;
		}
		x >>= 1;
	}

	printf("%d\n", count);
}

