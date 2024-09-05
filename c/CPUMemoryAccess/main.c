#include "MemManage.h"
#include <stdio.h>


#define ARRAY_SIZE 7

int main()
{
	
	char dest[ARRAY_SIZE];
	char src[ARRAY_SIZE] = {'5','6','3','4','5','6','7'};

	size_t i = 0;


	
	
	MemSet(dest, '0', sizeof(dest));

	MemCpy(src, (src + 1), sizeof(src));
	MemMove(src+1, src, 6);

	for(i = 0; i < 7; ++i)
	{
		printf("%c\n", src[i]);	
	}
	
	return 0;
}

	
