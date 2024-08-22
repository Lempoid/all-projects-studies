/*
Alex Breger
Reviewed: Ben Bortkevich
*/

#include <stdio.h> /*printf*/
#include <string.h> /*strcat*/
#include <stdlib.h> /*atoi atof size_t*/
#include "heteroArray.h"

#define STRING_BUFFER 50

void Add(ArrayType* array, size_t size, int toAdd)
{
	size_t i;
	char intToString[STRING_BUFFER];

	for(i = 0; i < size; ++i)
	{
		switch(array[i].type)
		{
		case IS_STR:
			sprintf(intToString, "%d", toAdd);
			strcat((char*)array[i].data, intToString);
			break;
		case IS_INT:
			*(int*)array[i].data = *(int*)array[i].data + toAdd;
			break;
		case IS_FLOAT:
			*(float*)array[i].data = *(float*)array[i].data + toAdd;
			break;
		}
	}
}
void Print(ArrayType* array, size_t size)
{
	size_t i;
	
	for(i = 0; i < size; ++i)
	{
		switch(array[i].type)
		{
			case IS_STR:
			printf("%s\n", (char*)array[i].data);
			break;
		case IS_INT:
			printf("%d\n", *(int*)array[i].data);
			break;
		case IS_FLOAT:
			printf("%f\n", *(float*)array[i].data);
			break;
		
		}
	}
}

void CleanUp(ArrayType* array, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
	{
		free(array[i].data);
	}
}
