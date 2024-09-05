#include <stdio.h>

#define IS_BIG_ENDIAN (!*(char*)&(short){1})

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
