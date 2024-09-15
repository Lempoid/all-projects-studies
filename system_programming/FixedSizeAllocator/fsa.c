#include <stdio.h> /*printf*/
#include <stddef.h> /*size_t*/
#include <stdint.h> /*uintptr_t*/
#include "fsa.h"

struct fsa
{
	void* first_free;
	size_t block_size;
	size_t total_blocks;
}

/* Forward declaration of the fixed-size allocator structure */
typedef struct fsa fsa_t

/* Function to determine the amount of memory required for the allocator, including overhead */
size_t FsaSuggestSize(size_t block_size, size_t block_num)
{
	return (size_t)(block_size * block_num + sizeof(fsa_t) + (sizeof(size_t) - 1))
}

/* Initializes the memory pool and sets up the linked list of free blocks */
fsa_t *FsaInit(void *memory, size_t block_size, size_t pool_size)
{
	uintptr_t first_block;
	void** current_block;
	void** last_block;

	if(NULL == memory && 0 == block_size && 0 == pool_size)
	{
		printf("Initialization failed. returning NULL.\n");
		return NULL;
	}

	fsa_t *fsa = (fsa_t*)memory;
	fsa->block_size = block_size;
	fsa->total_blocks = pool_size;

	first_block = uintptr_t(memory) + sizeof(fsa_t);
	first_block = (first_block + sizeof(size_t) - 1) & ~(sizeof(size_t) - 1);
	fsa->first_free = first_block;

	for(i = 0; i < pool_size; ++i)
	{
		current_block = (void**)(char*)first_block + i * block_size;
		*current_block = (char*)current_block + block_size;
	}

	last_block = (void**)(char*)first_block + ((pool_size - 1) * block_size);
	*last_block = NULL;

	return fsa;
}

/* Allocates a block of memory from the allocator */
void *FsaAlloc(fsa_t *fsa_mngr);

/* Deallocates a block of memory, returning it to the free list */
void FsaFree(void *to_free, fsa_t *fsa_mngr);

/* Returns the number of free blocks available in the allocator */
size_t FsaCountFree(fsa_t *fsa_mngr)
{
	void* runner = fsa_mngr->first_free;
	size_t count = 0;

	while(NULL != runner)
	{
		++count;
		runner = *(void**)runner;
	}

	return count;
}

