#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fsa.h"

int main()
{
	size_t	block_size = 10;
	char 	value[] = "aaaavvvv";
	size_t	block_num = 4;
	size_t 	result = 0;
	void*	ptr = NULL;
	void*	manager_ptr = NULL;
	void*	curr_alloc = NULL;
	void*	check = NULL;
	
	result = FsaSuggestSize(block_size, block_num);	/* suggestsize */
	
	printf("%lu\n", result);
	
   	ptr = malloc(result); 
	
	if (NULL == ptr)
	{
		perror("failed allocating malloc\n");
	}
	
	manager_ptr = FsaInit(ptr, result, block_size);	/* init */
	
	if (NULL == manager_ptr)
	{
		perror("failed allocating manager_ptr\n");
	}
	
	curr_alloc = FsaAlloc(manager_ptr);		/* allocs check */
	
	if (NULL == curr_alloc)
	{
		perror("failed Alloc1\n");
	}
	
	check = memcpy(curr_alloc, value, 8);
	
	if (NULL == check)
	{
		perror("failed memcpy1\n");
	}
						
	curr_alloc = FsaAlloc(manager_ptr);
	
	if (NULL == curr_alloc)
	{
		perror("failed Alloc2\n");
	}
	
	check = memcpy(curr_alloc, value, 8);
	
	if (NULL == check)
	{
		perror("failed memcpy2\n");
	}
	
	curr_alloc = FsaAlloc(manager_ptr);
	
	if (NULL == curr_alloc)
	{
		perror("failed Alloc3\n");
	}
	
	check = memcpy(curr_alloc, value, 8);
	
		printf("%s\n", (char*)ptr);
	
	if (NULL == check)
	{
		perror("failed memcpy3\n");
	}
	
	curr_alloc = FsaAlloc(manager_ptr);
	
	if (NULL == curr_alloc)
	{
		perror("failed Alloc4\n");
	}
	
	result = FsaCountFree(manager_ptr);	/* countfree check */
					
	check = memcpy(curr_alloc, value, 8);
	
	if (NULL == check)
	{
		perror("failed memcpy4\n");
	}
	
		printf("%s\n", (char*)ptr);
		
	FsaFree(curr_alloc, manager_ptr);	/* check free + alloc */			
	
	curr_alloc = FsaAlloc(manager_ptr);
	
	if (NULL == curr_alloc)
	{
		perror("failed Alloc5\n");
	}
	
	check = memcpy(curr_alloc, value, 8);
	
	if (NULL == check)
	{
		perror("failed memcpy5\n");
	}
	
		printf("%s\n", (char*)ptr);
		
	FsaFree(curr_alloc, manager_ptr);
	
	curr_alloc = FsaAlloc(manager_ptr);
	
	if (NULL == curr_alloc)
	{
		perror("failed Alloc5\n");
	}
	
	check = memcpy(curr_alloc, value, 8);
	
	if (NULL == check)
	{
		perror("failed memcpy5\n");
	}
	
	printf("%s\n", (char*)ptr);
	
	return 0;
}
