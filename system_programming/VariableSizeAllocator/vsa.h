#ifndef __VSA_H_CR8__
#define __VSA_H_CR8__

/* API- Varialbe Size allocator*/

typedef struct vsa vsa_t;

/* Function to initialize the memory pool */
vsa_t *VsaInit(size_t total memory, void *pool_memory);

/* Function to allocate a specific size of memory */
void *VsaAlloc(vsa_t *mngr , size_t memory_size);

/* Function to free allocated memory */
void VsaFree(void *to_free );

/* Function to detrmine the largest available size of memory */
size_t VsaLargestChunkAvailable(vsa_t *vsa_mngr);

#endif /* __VSA_H_CR8__ */ 