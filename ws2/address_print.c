#include <stdio.h>
#include <stdlib.h>

int main()
{
	static int s_i = 7;
	int i = 7;
	int *ptr = &i;
	int *ptr2 = (int *)malloc(sizeof(int));
	
	if(ptr)
	{
		int **ptr3 = &ptr;
	}
printf("%p\n", ptr2);
	free(ptr2);

	printf("%p\n", &s_i);
	printf("%p\n", &i);
	printf("%p\n", ptr);
	printf("%p\n", ptr2);
	//printf("%p", s_i);
	return 0;	
}
