#include <stdio.h>

void ByteMirror(unsigned x);
void ByteMirrorLoop(unsigned x);


int main()
{
	ByteMirror((unsigned) 8);
	ByteMirrorLoop((unsigned)8);
	return 0;
}

void ByteMirror(unsigned x)
{
	x = (((x & 0xAA) >> 1) | ((x & 0x55) << 1));
	x = (((x & 0xCC) >> 2) | ((x & 0x33) << 2));
	x = (((x & 0xF0) >> 4) | ((x & 0x0F) << 4));
	
	printf("%d\n", x >> 4);
}

void ByteMirrorLoop(unsigned x)
{
	unsigned tmp = 0;

	while(x != 0)
	{
		tmp <<= 1;
		tmp |= x & 1;
		x >>= 1;
	}

	printf("%d\n", tmp);
}
