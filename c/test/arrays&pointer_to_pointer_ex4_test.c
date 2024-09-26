/*
Alex Breger
Review: Ben Bortkevich 11.8.24
*/

#include <stdlib.h>
#include "count_env_vars.h"

extern char **environ;

int main()
{
	size_t i;
	size_t count = CountEnvVars(environ);
	char** buffer = ToLowerEnv(environ, count);
	PrintEnv(buffer, count);
	
	for (i = 0; i < count; ++i)
	{
		free(buffer[i]);
	}
	free(buffer);
	
	return 0;
}
