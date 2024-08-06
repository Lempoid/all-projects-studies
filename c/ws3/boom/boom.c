#include <stdio.h> /*printf*/
#include <string.h> /*strchr*/
#include "boom.h"


void boom(int const start, int const end)
{
	const int NUMBER_TO_BOOM = 7;
	char int_to_string[12]; /* Max int number*/
	int i;
	
	for(i = start; i <= end; ++i)
	{
		sprintf(int_to_string,"%d",i);
		
		if((0 != i % NUMBER_TO_BOOM) && (strchr(int_to_string,(char)NUMBER_TO_BOOM) != NULL))
		{
			printf("%d", i);
		}
		else
		{
			printf("BOOM");
		}
	}
}
