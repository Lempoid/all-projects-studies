/*
Alex Breger
Reviewed: Ben Bortkevich
*/

#include <stdlib.h> /*malloc*/
#include <string.h> /*strcpy*/
#include "heteroArray.h"

#define ARRAY_SIZE 3

int main()
{
	ArrayType array[ARRAY_SIZE];
	

	array[0].data = malloc(2*sizeof(char));
	array[0].data = strcpy(array[0].data, "5");
	array[0].type = IS_STR;

	array[1].data = malloc(sizeof(float));
	*(float*)array[1].data = 5.5;
	array[1].type = IS_FLOAT;

	array[2].data = malloc(sizeof(int));
	*(int*)array[2].data = 5;
	array[2].type = IS_INT;

	Add(array,ARRAY_SIZE,10);
	Print(array,ARRAY_SIZE);

	CleanUp(array, ARRAY_SIZE);

	return 0;
}