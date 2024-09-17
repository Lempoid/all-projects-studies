#include <stdio.h>
#include <errno.h>
#include "vsa.h"

struct vsa
{
    void* pool_start;
    size_t total_size;
};

vsa_t* VsaInit(size_t total_memory, void* pool_memory) 
{
	vsa_t* vsa = (vsa_t*)pool_memory;
	size_t available_size;

	if (!pool_memory || total_memory <= sizeof(vsa_t)) 
	{
		perror("Initialization failed\n");
        return NULL;
    }
    
    
    vsa->total_size = total_memory;
    
    vsa->pool_start = (char*)pool_memory + sizeof(vsa_t);
    available_size = total_memory - sizeof(vsa_t);
    
    *(size_t*)vsa->pool_start = available_size;
    
    return vsa;
}

void* VsaAlloc(vsa_t* vsa, size_t memory_size) 
{
	size_t* current;
	size_t* best_fit_block = NULL;
	size_t best_size_block = (size_t) - 1;
	size_t remaining_size;
	size_t block_size;
	int is_allocated;

	if(!vsa || 0 == memory_size)
	{
		perror("Allocation failed\n");
		return NULL;
	}

	current = (size_t*)vsa->pool_start;
	remaining_size = vsa->total_size;

	while(remaining_size > 0)
	{
		block_size = *current & ~0x1;
		is_allocated = *current & 0x1;

		if(0 == is_allocated && block_size >= memory_size)
		{
			if(block_size < best_size_block)
			{
				best_fit_block = current;
				best_size_block = block_size;
			}
		}
		current = (void*)((char*)current + block_size);
		remaining_size -= block_size;
	}

	if(NULL != best_fit_block)
	{
		if(block_size > (size_t) - 1)
		{
			block_size = (size_t) -1;
		}
		vsa->pool_start = best_fit_block;
		*(void*)vsa->pool_start |= 0x1;
		vsa->total_size = block_size;
		return vsa->pool_start;
	}

	
	
	return NULL;
	
}

void VsaFree(void* to_free) 
{
}

size_t VsaLargestChunkAvailable(vsa_t* vsa) 
{
}
