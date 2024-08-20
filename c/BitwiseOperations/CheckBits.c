/*
Alex Breger
Reviewed: Ben Bortkevich 19.8.24
*/

#include <stdio.h> /*printf*/

int BothOn(unsigned char c);
int AtLeastOneOn(unsigned char c);
int SwapBits(unsigned char c);

int main()
{
	printf("%d\n",BothOn(68));
	printf("%d\n", AtLeastOneOn(4));
	printf("%d\n", SwapBits(5));
	return 0;
}


int BothOn(unsigned char c)
{
	return (c & 0x44);
}

int AtLeastOneOn(unsigned char c)
{
	return ((c & 0x04) | (c & 0x40));
}

int SwapBits(unsigned char c)
{
	unsigned char bit1 = c & 0x04;
	unsigned char bit2 = c & 0x10;
	unsigned char tmp;

	bit1 = bit1 << 2;
	bit2 = bit2 >> 2;
	tmp = bit1 | bit2;

	c = c & 0x14;

	c = c | tmp;

	return tmp;
}