#include <stdio.h>

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
	return (c ^ 0x14);
}