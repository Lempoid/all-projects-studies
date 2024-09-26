/*
Alex Breger
Reviewed: Ben Bortkevich 19.8.24
*/

#include <stdio.h> /*printf*/

int main()
{
	unsigned int arr[4] = {5,255,7,13};
	int i = 0 ;
	int count = 0;
	unsigned int tmp = 0;

	for(i = 0; i < 4; ++i)
	{
		count = 0;
		tmp = arr[i];

		while(arr[i])
		{
			if(arr[i] & 1)
			{
				++count;
			}
			
			arr[i] >>= 1;
			
			if(3 == count)
			{
				printf("%d\n", tmp);
				break;
			}
		
		}

		
	}

	return 0;
}