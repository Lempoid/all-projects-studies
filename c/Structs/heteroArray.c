/*
Alex Breger
Reviewed: Ben Bortkevich 22.8.24
*/

#include <stdio.h> /*printf*/
#include <string.h> /*strcat */
#include <stdlib.h> /*free*/
#include "heteroArray.h"

#define STRING_BUFFER 50

void AddInt(void* data, int toAdd)
{
	*(int*)data += toAdd;
}

void AddFloat(void* data, int toAdd)
{
	*(float*)data += toAdd;
}

void AddStr(void* data, int toAdd)
{
	char intToString[STRING_BUFFER];
	sprintf(intToString, "%d", toAdd);
	strcat((char*)data, intToString);
}

void PrintInt(void* data)
{
	printf("%d\n", *(int*)data);
}

void PrintFloat(void* data)
{
	printf("%f\n", *(float*)data);
}

void PrintStr(void* data)
{
	printf("%s\n", (char*)data);
}

void CleanUp(void* data)
{
	free(data);
}
