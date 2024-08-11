/*
Alex Breger
Review: Ben Bortkevich
*/

#include <stdio.h> /*scanf printf*/
#include <stdlib.h> /*calloc*/
#include <assert.h> /*assert*/
#include "sum2darray.h"


#define ROW 2
#define COL 2
int main()
{
	int result_len;
	int* result_arr = NULL;
	int arr[ROW][COL] = {{2,1},{2,2}};
	printf("Enter number of rows\n");
	result_len = scanf("%d", &result_len);
	result_arr = calloc(result_len, sizeof(int));
	assert(NULL != result_arr);
	Sum2D(arr,ROW,COL,result_arr);
		
	printf("%d\n%d", result_arr[0], result_arr[1]);
	
	free(result_arr);

return 0;
}
