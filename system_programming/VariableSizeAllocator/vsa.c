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
	size_t* next;
	size_t next_block_size;
	int next_is_allocated;
	size_t* best_fit_block = NULL;
	size_t best_size_block = (size_t) - 1;
	size_t remaining_size;
	size_t block_size;
	int is_allocated;
	size_t size_metadata = sizeof(size_t);

	if(!vsa || 0 == memory_size)
	{
		perror("Allocation failed\n");
		return NULL;
	}

	current = (size_t*)vsa->pool_start;
	remaining_size = vsa->total_size;

	while(remaining_size > size_metadata)
	{
		block_size = *current & ~0x1;
		is_allocated = *current & 0x1;
		next = (void*)((char*)current + block_size);

		if(0 == is_allocated && remaining_size > block_size)
		{
			next_block_size = *next & ~0x1;
			next_is_allocated = *next & 0x1;
			if(0 == next_is_allocated)
			{
				*current = block_size + next_block_size;
				continue;
			}
		}

		current = next;
		remaining_size -= block_size;
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
		current = (size_t*)((char*)current + block_size);
		remaining_size -= block_size;
	}

	if(NULL != best_fit_block)
	{
		size_t remaining_block_size = best_size_block - memory_size;
		
		if(remaining_block_size >= size_metadata + size_metadata)
		{
			next = (size_t*)((char*)best_fit_block + memory_size + size_metadata);
			best_fit_block = memory_size | 0x1;
		}
		else
		{
			*best_fit_block |= 0x1;
		}
		return (void*)((char*)best_fit_block + size_metadata);
	}
	
	return NULL;
}

void VsaFree(void* to_free) 
{
	size_t* meta_data;
	
	if(NULL == to_free)
	{
		perror("The pointer is NULL, nothing to free\n");
		return;
	}

	meta_data = (size_t*)((char*)to_free - sizeof(size_t));
	*meta_data = *meta_data & ~0x1;
}

size_t VsaLargestChunkAvailable(vsa_t* vsa) 
{
	size_t* current_block;
	size_t* next_block;
	size_t next_block_size;
	int is_next_allocated;
	size_t remaining_size;
	size_t current_block_size;
	int is_current_allocated;
	size_t size_metadata = sizeof(size_t);
	size_t largest_free_block = 0;

	if(NULL == vsa)
	{
		perror("The VSA is not initialized. Returning 0.\n");
		return 0;
	}

	current_block = (size_t*)vsa->pool_start;
	remaining_size = vsa->total_size;

	while(remaining_size > size_metadata)
	{
		current_block_size = *current_block & ~0x1;
		is_current_allocated = *current_block & 0x1;
		next_block = (void*)((char*)current_block + current_block_size);



		if(0 == is_current_allocated)
		{
			if(current_block_size > largest_free_block)
			{
				largest_free_block = current_block_size;
			}

			if(remaining_size > current_block_size + size_metadata)
			{
				next_block_size = *next_block & ~0x1;
				is_next_allocated = *next_block & 0x1;
			}

			if(0 == is_next_allocated)
			{
				*current_block = current_block_size + next_block_size;
				continue;
			}

			current_block = (size_t*)((char*)current_block + current_block_size);
			remaining_size -= current_block_size;
		}
			
	}
	
	return largest_free_block;
}
