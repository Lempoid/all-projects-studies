/*
Alex Breger
Reviewed: Ben Bortkevich 22.8.24
*/
#include <stddef.h>
#include "heteroArray.h"

#define ARRAY_SIZE 3

int main()
{
	size_t i;
	ArrayType array[ARRAY_SIZE];
	int x = 5;
	float y = 6.6;
	char string[100] = "ab";

	array[0].data = string;
	array[0].printP = PrintStr;
	array[0].addP = AddStr;
	array[0].cleanUpP = CleanUp;

	array[1].data = &y;	
	array[1].printP = PrintFloat;
	array[1].addP = AddFloat;
	array[1].cleanUpP = CleanUp;
	
	array[2].data = &x;
	array[2].printP = PrintInt;
	array[2].addP = AddInt;
	array[2].cleanUpP = CleanUp;

	for (i = 0; i < ARRAY_SIZE; ++i)
	{
		array[i].printP(array[i].data);
		array[i].addP(array[i].data, 10);
		array[i].printP(array[i].data);

	}
	
	/*for (i = 0; i < ARRAY_SIZE; ++i)
	{
		if(array[i].data)
		{
			array[i].cleanUpP(array[i].data);
		}
	}*/

	return 0;
}