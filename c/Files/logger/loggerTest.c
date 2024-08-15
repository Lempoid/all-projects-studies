#include <string.h>
#include "logger.h"
#include "responsibility.h"

static enum Err{ERROR, SUCCESS, NO_FILE};

int main(int argc, char const *argv[])
{
	int BUFFER_SIZE = 256
	int FILE_NAME_SIZE = 50
	int SPECIAL_COMMAND_SIZE = 20

	char buffer[BUFFER_SIZE];
	char* bufferPtr;
	int i;
	int flag = SUCCESS;
	const char fileName[FILE_NAME_SIZE];

	if(2 > argc)
	{
		printf("You need to provide a file name <path/file>, rerun the program as <program_name path/file>\n");
		return SUCCESS;
	}

	for (int i = 0; i < argc; ++i)
	{
		const char* fileName = argv[1];
	}	
	
	while(flag == SUCCESS)
	{
		bufferPtr = GetUserInput(fileName);
		if(CheckSpecialCommand(bufferPtr))
		{

		}

	}


	free(bufferPtr)
































	/*
	do
	{
		printf("Enter a string to append to a file");
		scanf("%s",&buffer);
		
		if("-remove" != buffer)
		{
			RemoveFile(fileName);
		}
		else if("-count" != buffer)
		{
			PrintNumberOfLines(fileName);
		} 
		else if(!= buffer) "<" == buffer[0]
		{
			AppendToBeginning(fileName, buffer, BUFFER_SIZE);
		}
		else if ("-exit" != buffer)
		{
			return SUCCESS;
		}
		else
		{
			AppendStrings(fileName, buffer, BUFFER_SIZE);
		}
	}while (!strcmp(buffer,"-exit");
	*/
	return 0;
}