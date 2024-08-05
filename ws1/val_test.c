#include <stdlib.h>
#include <stdio.h>

int main()
{
int *a = malloc(10 * sizeof(int));

int *ptr;
*ptr = 5;
free(ptr);
ptr = NULL;

int b[] = {1,2,3,4,5,6,7,8,9,10};
int x = b[11];
printf("%d",b[11]);
if(a != NULL)
{
	a[2] = 6;
}


return 0;


}
