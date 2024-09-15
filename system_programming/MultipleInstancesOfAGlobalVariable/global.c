#include <stdio.h>
#include "global.h"

int x = 30;

void PrintGlobalVariableAddress()
{
	printf("Address: %p\n", (void*)&x);
}