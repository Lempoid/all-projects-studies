#include "g.h"

#include <stdio.h>

int main()
{
	printf("%d\n", g_s);
	Foo();
	printf("%d\n", g_s);
	return 0;
}