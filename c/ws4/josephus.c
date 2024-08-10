#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* arr[100] = {[0 ... 99] = 1} ;
	int jump = 1;
	int i = 0;
	
	while(0 != arr[i + jump])
	{
		if(1 == arr[i])
		{
			arr[i + jump] = 0;
		}
		
		
		if(99 <= i)
		{
			jump *= 2;
			i = 0;
		}
		
	}
	
	

	return 0;
}
