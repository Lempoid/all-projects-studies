#include <stdio.h> /*printf*/
#include <stdlib.h> /*environ malloc*/
#include <string.h> /*tolower*/
#include "count_env_vars.h"

extern char **environ;

size_t count_env_vars()
{
	size_t count = 0;
	char** runner = environ;
	
	while (NULL != *runner)
	{
		++count;
	}
	
	return count;
}

char** to_lower_env(char** env_vars, size_t size)
{
	char** buffer = malloc(sizeof(*env_vars) * size);
	char* runner = buffer;
	
	while(NULL != runner)
	{
		runner = tolower(**env_vars);
	}
	
	*start = '\0';
	
	return buffer;
}
