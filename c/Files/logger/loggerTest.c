/*
Alex Breger
Review: Ben Bortkevich 19.8.24
*/

#include <stdlib.h> /*free* size_t*/
#include <stdio.h> /*printf*/
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
		{"<", CompareCommands, AppendToBeginning},
		{"-count", CompareCommands, PrintNumberOfLines},
		{"-remove", CompareCommands, RemoveFile},
		{"-exit",CompareCommands, Exit} 		
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