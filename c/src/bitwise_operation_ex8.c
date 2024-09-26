/*
Alex Breger
Reviewed: Ben Bortkevich 19.8.24
*/

#include <stdio.h> /*printf*/

int main()
{
	int x = 5;
	int y = 10;

	printf("x: %d,y: %d\n",x,y );
	
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;

	printf("x: %d,y: %d\n",x,y );
	
	return 0;
}