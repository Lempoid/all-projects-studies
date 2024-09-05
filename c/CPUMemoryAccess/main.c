#include "MemManage.h"
#include <stdio.h>


#define ARRAY_SIZE 50

int main()
{
	
	int dest[ARRAY_SIZE];
	int src[ARRAY_SIZE] = {5,6,3,4,5,6,7,10000};

	size_t i = 0;


	
	
	MemSet(dest, 9, sizeof(dest));

	MemCpy(dest, src, sizeof(src));

	MemMove(dest, src, sizeof(src));

	for(i = 0; i < ARRAY_SIZE; ++i)
	{
		printf("%d\n", dest[i]);	
	}
	
	return 0;
}