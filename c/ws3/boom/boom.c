#include <stdio.h> /*printf*/
#include <string.h> /*strchr*/
#include "boom.h"


void boom(int const start, int const end)
{
	const char TO_BOOM_ON = '7';
	char int_to_string[12]; /* Max int number*/
	int i;
	
	for(i = start; i <= end; ++i)
	{
		sprintf(int_to_string,"%d",i);
		
		if((0 != i % (TO_BOOM_ON - 0)) && NULL == (strchr(int_to_string, TO_BOOM_ON)))
		{
			printf("%d\n", i);
		}
		else
		{
			printf("%d: BOOM\n", i);
		}
	}
}
