#include <stdio.h>

int main()
{
	float x = 3.14;
	int i = 0;
	unsigned int* p = (unsigned int*) &x;

    for (i = 31; i >= 0; i--) 
    {
        printf("%d", (*p >> i) & 1);
        if (i % 4 == 0) 
        {
            printf(" ");
        }
    }
    printf("\n");

	return 0;
}