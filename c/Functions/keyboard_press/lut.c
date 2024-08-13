/*
Author: Alex Breger
Reviewed: Ben Bortkevich 13.8.24
*/

#include <stdio.h> /*getchar*/
#include "keyboardCheck.h"
#include "lut.h"

typedef void (*arrayFunc)(void);

void Lut()
{	
	void (*array[256])();
	int i = 0;
	char user_input;
	
	arrayFunc pointer_to_func = EmptyFunc;
	arrayFunc pointer_a = PrintA;
	arrayFunc pointer_t = PrintT;
	arrayFunc pointer_esc = Esc;
	
	for(i = 0; i<256;++i)
	{
		array[i] = pointer_to_func;
	}
	
	
	array[27] = pointer_esc;
	array['A'] = pointer_a;
	array['T'] = pointer_t;
	
	do
	{
	user_input = getchar();
	array[(unsigned)user_input]();
	}while(27 != user_input);
}

void EmptyFunc()
{
}
