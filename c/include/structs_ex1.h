/*
Alex Breger
Reviewed: Ben Bortkevich 22.8.24
*/

#ifndef __HETEROARRAY_H__
#define __HETEROARRAY_H__

#include <stddef.h>

typedef void (*PrintP)(void* data);
typedef void (*AddP)(void* data, int toAdd);
typedef void (*CleanUpP)(void* data);

typedef struct 
{
	void* data;
	PrintP printP;
	AddP addP;
	CleanUpP cleanUpP;
}ArrayType;

void AddInt(void* data, int toAdd);
void AddFloat(void* data, int toAdd);
void AddStr(void* data, int toAdd);
void PrintInt(void* data);
void PrintFloat(void* data);
void PrintStr(void* data);
void CleanUp(void* data);

#endif /*__HETEROARRAY_H__*/