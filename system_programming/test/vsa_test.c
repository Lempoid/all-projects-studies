/*
Alex Breger
Reviwed: Shai Meguideche 18.9.24
*/

#include <stdio.h>
#include <stdlib.h>
#include "vsa.h"  /* Including the VSA header file */

/* Function to test VSA initialization */
void TestVsaInit() {
    size_t pool_size = 1024;              /* Define the size of the memory pool */
    void *memory_pool = malloc(pool_size);/* Allocate the memory pool */
    vsa_t *vsa = VsaInit(pool_size, memory_pool);  /* Initialize the VSA */

    /* Check if VSA is initialized correctly (cannot directly check internal fields) */
    if (vsa != NULL) {
        printf("TestVsaInit: Passed\n");
    } else {
        printf("TestVsaInit: Failed\n");
    }

    free(memory_pool);  /* Free the memory pool */
}

/* Function to test VSA allocation */
void TestVsaAlloc() {
    size_t pool_size = 1024;
    void *memory_pool = malloc(pool_size);
    vsa_t *vsa = VsaInit(pool_size, memory_pool);

    void *alloc1 = VsaAlloc(vsa, 100);  /* Allocate 100 bytes */
    void *alloc2 = VsaAlloc(vsa, 200);  /* Allocate 200 bytes */
    void *alloc3 = VsaAlloc(vsa, 300);  /* Allocate 300 bytes */

    if (alloc1 && alloc2 && alloc3) {
        printf("TestVsaAlloc: Passed\n");
    } else {
        printf("TestVsaAlloc: Failed\n");
    }

    free(memory_pool);
}

/* Function to test VSA free and coalescing of blocks */
void TestVsaFree() {
    size_t pool_size = 1024;
    void *memory_pool = malloc(pool_size);
    vsa_t *vsa = VsaInit(pool_size, memory_pool);
    void *alloc1 = VsaAlloc(vsa, 100);
    void *alloc2 = VsaAlloc(vsa, 200);
    void *alloc3 = VsaAlloc(vsa, 300);
    size_t largest_chunk; /* Declare all variables at the start */

    VsaFree(alloc2);  /* Free the second block */
    largest_chunk = VsaLargestChunkAvailable(vsa);

    /* Check if largest chunk is at least 200 after freeing the second allocation */
    if (largest_chunk >= 200) {
        printf("TestVsaFree: Passed\n");
    } else {
        printf("TestVsaFree: Failed\n");
    }

    VsaFree(alloc1);
    VsaFree(alloc3);
    largest_chunk = VsaLargestChunkAvailable(vsa);

    /* Check if all memory is coalesced properly */
    /* Since we cannot use sizeof on private structures, focus on logical checks */
    if (largest_chunk == pool_size - 100 - 200 - 300) { /* Expected largest after all frees */
        printf("TestVsaFree (full coalescing): Passed\n");
    } else {
        printf("TestVsaFree (full coalescing): Failed\n");
    }

    free(memory_pool);
}

/* Function to test the largest available chunk */
void TestVsaLargestChunkAvailable() {
    size_t pool_size = 1024;
    void *memory_pool = malloc(pool_size);
    vsa_t *vsa = VsaInit(pool_size, memory_pool);
    size_t largest_chunk; /* Declare all variables at the start */

    VsaAlloc(vsa, 100);
    VsaAlloc(vsa, 200);

    largest_chunk = VsaLargestChunkAvailable(vsa);

    /* Check if the largest chunk available is correctly calculated */
    if (largest_chunk > 0) {
        printf("TestVsaLargestChunkAvailable: Passed\n");
    } else {
        printf("TestVsaLargestChunkAvailable: Failed\n");
    }

    free(memory_pool);
}

int main() {
    TestVsaInit();                  /* Test the initialization of VSA */
    TestVsaAlloc();                 /* Test memory allocation in VSA */
    TestVsaFree();                  /* Test freeing memory and coalescing */
    TestVsaLargestChunkAvailable(); /* Test largest chunk functionality */

    return 0;
}
