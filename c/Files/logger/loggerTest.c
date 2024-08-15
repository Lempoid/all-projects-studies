#include <string.h>
#include "logger.h"

#define BUFFER_SIZE = 256
#define FILE_NAME_SIZE = 50
#define SPECIAL_COMMAND_SIZE = 20
int main(int argc, char const *argv[])
{
	char buffer[BUFFER_SIZE];
	int i;
	const char fileName[FILE_NAME_SIZE];
	struct responsibility
	{
		char* stringToCompare;
		int (*CompareFunction)(char*, char*);
		void (*OperationFunction)();
	}

	if(2 > argc)
	{
		printf("You need to provide a file name <path/file>, rerun the program as <program_name path/file>\n");
		return 0;
	}

	for (int i = 0; i < argc; ++i)
	{
		const char* fileName = argv[1];
	}	
	
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
		}
		else if ("-exit" != buffer)
		{
			return 0;
		}
		}
		else
		{
			AppendStrings(fileName, buffer, BUFFER_SIZE);
		}

	}while (!strcmp(buffer,"-exit");
	
	return 0;
}