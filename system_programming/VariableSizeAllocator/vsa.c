#include <stdio.h>
#include "vsa.h"

typedef struct vsa
{
    void* memory_start;
    void* memory_end;
    size_t total_memory;
} vsa_t;

vsa_t* VsaInit(size_t total_memory, void *pool_memory)
{
	vsa_t vsa_mngr = (vsa_t*)malloc(sizeof(vsa_t));
	if (NULL == vsa_mngr)
	{
        return NULL;
    }
    
	vsa_mngr->memory_start = pool_memory;
	vsa_mngr->memory_end = pool_memory + memory * sizeof(pool_memory);
	vsa_mngr->total_memory = total_memory;

	return vsa_mngr;
}