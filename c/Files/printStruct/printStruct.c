/*
Alex Breger
Review: Diana Mitnitsky
*/

#include <stdio.h> /*printf*/
#include "printStruct.h"

int main()
{
	int i;
	struct print_me
	{
		int to_print;
		void (*PrintP)(int);
	};

	struct print_me arr[10];

	for (i = 0; i < 10; ++i)
	{
		arr[i].to_print = i;
		arr[i].PrintP = Print; 
	}

	for (i = 0; i < 10; ++i)
	{
		arr[i].PrintP(arr[i].to_print);
	}

	return 0;
}


void Print(int num)
{
	printf("%d\n",num);
}