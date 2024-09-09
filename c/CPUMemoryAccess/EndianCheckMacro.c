#include <stdio.h>

#define IS_BIG_ENDIAN ((*(unsigned short*)"\0\xff") == 0xff)

int main()
{
	
	if(IS_BIG_ENDIAN)
	{
		printf("Little endian\n");
	}
	else
	{
		printf("Big endian\n");

	}
	
	return 0;
}	
