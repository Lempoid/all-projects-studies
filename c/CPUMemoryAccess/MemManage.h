#ifndef __MEMMANAGE_H__
#define __MEMMANAGE_H__

#include <stddef.h>


void* MemSet(void* dest, int c, size_t n);
void* MemCpy(void* dest_str, const void* src_str, size_t n);
void *MemMove(void *dest_str, const void *src_str, size_t num_bytes);
int IsOverlap(const void* dst,const void* src, size_t n);

#endif /*__MEMMANAGE_H__*/