/*
Alex Breger
Reviewed: Ben Bortkevich 19.8.24
*/

#include <stdio.h> /*printf*/

int AddOne(int x);

int main()
{
	int x = 5;
	printf("%d\n", AddOne(x));
	return 0;
}

int AddOne(int x)
{
	int m = 1;

	while (x & m)
	{
		x = x ^ m;
		m <<= 1;
	}

	x = x ^ m;

	return x;
}
