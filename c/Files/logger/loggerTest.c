#include <string.h>
#include "logger.h"
#include "responsibility.h"

int main(int argc, char const *argv[])
{
	const char* fileName;
	size_t sizeOfArray = 4;
	char* userInput;
	OpResult resultFromHandler;
	struct responsibility chainOfCommands[] = 
	{
		{"-remove", CompareCommands, RemoveFile},
		{"-count", CompareCommands, PrintNumberOfLines}, 
		{"-exit",CompareCommands, Exit}, 
		{"<", CompareCommands, AppendToBeginning}
	}
	
	if(2 > argc)
	{
		printf("You need to provide a file name <path/file>, rerun the program as %s <file name path>\n", argv[0]);
		return ERROR;
	}

	fileName = argv[1];

	while(1)
	{
		userInput = GetUserInput();
		if(NULL == userInput)
		{
			return MEM_ERROR;
		}

		resultFromHandler = Chain(userInput, chainOfCommands, sizeOfArray, fileName);
		free(userInput);

		if(OPERATION_EXIT == resultFromHandler)
		{
			break;
		}
		else if(OPERATION_FAILURE == resultFromHandler)
		{
			printf("Error occured during operation handling");
		}

	}

	return SUCCESS;
}