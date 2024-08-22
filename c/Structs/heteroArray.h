/*
Alex Breger
Reviewed: Ben Bortkevich
*/

#ifndef __HETEROARRAY_H__
#define __HETEROARRAY_H__

#include <stddef.h>

typedef enum 
{
	IS_STR, 
	IS_INT, 
	IS_FLOAT
}IsType;

typedef struct 
{
	void* data;
	IsType type;
}ArrayType;

void Add(ArrayType* array, size_t size, int toAdd);
void Print(ArrayType* array, size_t size);
void CleanUp(ArrayType* array, size_t size);

#endif /*__HETEROARRAY_H__*/