/*
Alex Breger
Review: Ben Bortkevich
*/

#include "sum2darray.h" /*Sum2D*/

void Sum2D(int array2d[][2], size_t row, size_t col, int result[])
{
	size_t i = 0;
	size_t j = 0;
	
	for(i = 0; i < row; ++i)
	{
		for(j = 0; j < col; ++j)
		{
			result[i] += array2d[i][j];
		}
	}
}
