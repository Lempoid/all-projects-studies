#include <string.h>/*strcmp*/
#include "logger.h"
#include "responsibility.h"


OpResult Chain(const char* specialCommand, CommandHandler* handler, size_t handlerSize, const char* fileName)
{
	size_t i = 0;

	for (i = 0; i < handlerSize; ++i)
	{
		if(handler[i].CompareFunction(specialCommand, handler[i].stringToCompare))
		{
			return handler[i].OperationFunction(fileName);
		}
	}

	return AppendStrings(fileName);
}


int CompareCommands(const char* userInput, const char* specialCommand)
{	
	if(0 == strcmp("<", userInput[0]))
	{
		return "<" == userInput[0];
	}

	return(0 == strcmp(userInput, specialCommand));
}