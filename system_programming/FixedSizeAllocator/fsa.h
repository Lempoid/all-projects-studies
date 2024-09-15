#ifndef __FSA_H_CR8__
#define __FSA_H_CR8__

#include <stddef.h> /* For size_t */

/* Forward declaration of the fixed-size allocator structure */
typedef struct fsa fsa_t;

/* Function to determine the amount of memory required for the allocator, including overhead */
size_t FsaSuggestSize(size_t block_size, size_t block_num);

/* Initializes the memory pool and sets up the linked list of free blocks */
fsa_t *FsaInit(void *memory, size_t block_size, size_t pool_size);

/* Allocates a block of memory from the allocator */
void *FsaAlloc(fsa_t *fsa_mngr);

/* Deallocates a block of memory, returning it to the free list */
void FsaFree(void *to_free, fsa_t *fsa_mngr);

/* Returns the number of free blocks available in the allocator */
size_t FsaCountFree(fsa_t *fsa_mngr);

#endif /*__FSA_H_CR8__*/ 
