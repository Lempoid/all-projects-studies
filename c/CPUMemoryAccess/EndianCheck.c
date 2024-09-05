/*
Alex Breger
Reviewed: Ben Bortkevich 5.9.24
*/

#include <stdio.h>

int main()
{
	int x = 1;
	char* c = (char*) &x;
	if(*c == 1)
	{
		printf("Little endian\n");
	}
	else
	{
		printf("Big endian\n");

	}
 
	
	return 0;
}