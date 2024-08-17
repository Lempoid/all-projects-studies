#include <stdlib.h> /*free*/
#include <stdio.h> /*Printf*/
#include "logger.h"
#include "responsibility.h"
#include "userData.h"

int main(int argc, char const *argv[])
{
	UserData userData;
	size_t sizeOfArray = 4;
	OpResult resultFromHandler;
	CommandHandler chainOfCommands[] = 
	{
		{"-remove", CompareCommands, RemoveFile},
		{"-count", CompareCommands, PrintNumberOfLines}, 
		{"-exit",CompareCommands, Exit}, 
		{"<", CompareCommands, AppendToBeginning}
	};
	
	if(2 > argc)
	{
		printf("You need to provide a file name <path/file>, rerun the program as %s <file name path>\n", argv[0]);
		return ERROR;
	}

	userData.fileName = argv[1];

	while(1)
	{
		userData.userInput = GetUserInput();
		if(NULL == userData.userInput)
		{
			return MEM_ERROR;
		}

		resultFromHandler = Chain(chainOfCommands, sizeOfArray, &userData);

		if(OPERATION_FAILURE == resultFromHandler)
		{
			AppendStrings(&userData);
		}

		free((char*)userData.userInput);

		if(OPERATION_EXIT == resultFromHandler)
		{
			break;
		}
		

	}

	return SUCCESS;
}