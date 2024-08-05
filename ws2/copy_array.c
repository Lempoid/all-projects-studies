#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void copy_array(int *a,size_t size_array,  int *b)
{
	
	//b = malloc(sizeof(a) * size_array);
	for(int i =0; i < size_array; i++)
		{
			b[i] = a[i];
			printf("%d", b[i]);
		}
			
}


int main()
{
	int array[] = {1,2,3,4,5};
	size_t size_array = sizeof(array)/sizeof(array[0]);
	int *arrayb = malloc(sizeof(array) * size_array);
	
	copy_array(array, size_array,  arrayb);

	printf("%d\n", arrayb[0]);

}
