/*
Alex Breger
Review: Ben Bortkevich 19.8.24
*/

#include <string.h>/*strcmp*/
#include "logger.h"
#include "responsibility.h"
#include "userData.h"


OpResult Chain(CommandHandler* handler, size_t handlerSize, UserData* userData)
{
	size_t i = 0;

	for (i = 0; i < handlerSize; ++i)
	{
		if(handler[i].CompareFunction(userData, handler[i].stringToCompare))
		{
			return handler[i].OperationFunction(userData);
		}
	}

	return OPERATION_FAILURE;
}


int CompareCommands(UserData* userData, const char* specialCommand)
{	
	if('<' == userData->userInput[0])
	{
		return 1;
	}

	return(0 == strcmp(userData->userInput, specialCommand));
}