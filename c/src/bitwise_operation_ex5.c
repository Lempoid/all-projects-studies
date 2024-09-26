/*
Alex Breger
Reviewed: Ben Bortkevich 19.8.24
*/

#include <stdio.h> /*printf*/

void ByteMirror(unsigned x);
void ByteMirrorLoop(unsigned x);


int main()
{
	ByteMirror((unsigned) 11);
	ByteMirrorLoop((unsigned)11);
	return 0;
}

void ByteMirror(unsigned x)
{
    x = ((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1);
    x = ((x & 0xCCCCCCCC) >> 2) | ((x & 0x33333333) << 2);
    x = ((x & 0xF0F0F0F0) >> 4) | ((x & 0x0F0F0F0F) << 4);
    x = ((x & 0xFF00FF00) >> 8) | ((x & 0x00FF00FF) << 8);
    x = (x >> 16) | (x << 16);
    
    printf("%u\n", x);
}

void ByteMirrorLoop(unsigned x)
{
	unsigned tmp = 0;
	int i;
	
    for (i = 0; i < 32; i++)
    {
        tmp <<= 1;
        tmp |= (x & 1);
        x >>= 1;
    }

	printf("%u\n", tmp);
}
