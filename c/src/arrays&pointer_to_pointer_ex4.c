/*
Alex Breger
Review: Ben Bortkevich 11.8.24
*/

#include <stdio.h> /*printf*/
#include <stdlib.h> /*environ malloc*/
#include <ctype.h> /*tolower*/
#include <string.h> /*strlen*/
#include <assert.h> /*assert*/
#include "count_env_vars.h"

size_t CountEnvVars(char** env_vars)
{
	size_t count = 0;
	char** runner = env_vars;
	
	while (NULL != *runner)
	{
		++count;
		++runner;
	}
	
	return count;
}

char** ToLowerEnv(char** env_vars, size_t size)
{
	char** buffer = malloc(sizeof(char*) * (size + 1));
	char** runner_env = env_vars;
	char** runner_buffer = buffer;
	size_t len;
	size_t i;
	
	while (NULL != *runner_env)
	{
		len = strlen(*runner_env);
		*runner_buffer = malloc(len + 1);
		
		assert(NULL != *runner_buffer);
		
		for(i = 0; i < len; ++i)
		{
			(*runner_buffer)[i] = tolower((*runner_env)[i]);
		}
		(*runner_buffer)[len] = '\0';
		
		++runner_env;
		++runner_buffer;
	}
	
	*runner_buffer = NULL;
	
	return buffer;
}

void PrintEnv(char** arrayToPrint, size_t size)
{
	size_t i;
	
	for (i = 0; i < size; ++i)
	{
		printf("%s\n", arrayToPrint[i]);
	}
}


