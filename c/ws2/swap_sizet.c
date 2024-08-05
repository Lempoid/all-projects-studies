#include <stdio.h>

void swap_t2(size_t **a, size_t **b);
void swap_t2p(size_t *a, size_t *b);

int main()
{	size_t x=5,y=6;
	
	//swap_t2(a,b);
	swap_t2p(&x,&y);
	printf("a: %lu, b: %lu\n",x,y);
}

void swap_t2(size_t **a, size_t **b)
{	
	size_t *tmp = *a;
        *a = *b;
        *b = *tmp;
	printf("a: %lu, b: %lu\n",a,b);
}

void swap_t2p(size_t *a, size_t *b)
{
//	int *tmp = *a;
//	*a = *b;
//	*b = *tmp;
	swap_t2(&a,&b);
}
