#include "logger.h"
#include "responsibility.h"

void Chain(const char* specialCommand)
{
	size_t sizeOfArray = 5;
	struct responsibility chainOfCommands[] = 
	{
		{"-remove", CompareCommands, RemoveFile},
		{"-count", CompareCommands, PrintNumberOfLines}, 
		{"-exit",CompareCommands, Exit}, 
		{"<", CompareCommands, AppendToBeginning}
	}
	
	for (int i = 0; i < sizeOfArray; ++i)
	{
		chainOfCommands
	}
}

int CompareCommands(const char* userInput, const char* specialCommand)
{
	int result;

	if(!strstr(userInput,specialCommand))
	{
		result = ERROR;
	}
	else
	{
		result = SUCCESS;
	}

	return result;
}