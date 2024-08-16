#include <stdlib.h>
#include <string.h>
#include "logger.h"

ErrCode CloseFile(FILE* file)
{
	ErrCode errorResult = SUCCESS;
	
	if(0 != fclose(file))
	{
		perror("Error closing file.\n");
		errorResult =  FILE_ERROR;
	}
	
	return errorResult;
}

FILE* OpenFile(const char* nameOfFile, const char* mode)
{
	FILE* filePointer = fopen(nameOfFile, mode);
	
	if(!filePointer)
	{
		perror("File Opening failed.\n");
	}

	return filePointer;
}

ErrCode RemoveFile(const char* nameOfFile)
{
	ErrCode errorResult = SUCCESS;

	if(0 != remove(nameOfFile))
	{
		perror("File removal failed.\n")
		errorResult = FILE_ERROR;
	}

	return errorResult;
}

ErrCode PrintNumberOfLines(const char* nameOfFile)
{
	size_t count = 0;
	char c;
	FILE* filePointer = OpenFile(nameOfFile, "r");

	if(NULL == filePointer)
	{
		return FILE_ERROR;
	}

	do
	{
		c = fgetc(filePointer);
		
		if('\n' == c)
		{
			++count;
		}

	}while(!feof(filePointer));

	printf("The number of lines is: %ul", count);

	return CloseFile(filePointer);
}

ErrCode AppendToBeginning(const char* nameOfFile)
{
	char byteToRead;
	char* userInput;

	FILE* originalFile = OpenFile(nameOfFile,"rb");
	FILE* tmpFile = OpenFile("tmpFile","ab");

	if(NULL == originalFile || NULL == tmpFile)
	{
		perror("Can't open the files in AppendToBeginning");
		return FILE_ERROR;
	}

	while(!feof(originalFile))
	{
		fread(&byteToRead, sizeof(char), 1, originalFile);
		fwrite(&byteToRead, sizeof(char), 1, tmpFile);
	}
	
	CloseFile(originalFile);
	CloseFile(tmpFile);
	
	originalFile = OpenFile(nameOfFile, "wb");
	if(NULL == originalFile)
	{
		return FILE_ERROR;
	}

	userInput = GetUserInput();
	if(NULL == userInput)
	{
		CloseFile(originalFile);
		return MEM_ERROR;
	}

	fwrite(userInput, sizeof(char), strlen(userInput), originalFile);
	fwrite("\n", sizeof(char), 1, originalFile);

	tmpFile = OpenFile("tmpFile","rb");
	if(NULL == tmpFile)
	{
		free(userInput);
		CloseFile(originalFile);
		return FILE_ERROR;
	}
	
	while(!feof(tmpFile))
	{
		fread(&byteToRead, sizeof(char), 1, tmpFile);
		fwrite(&byteToRead, sizeof(char), 1, originalFile);
	}

	CloseFile(originalFile);
	CloseFile(tmpFile);
	RemoveFile(tmpFile);
	free(userInput);

	return SUCCESS;
	
}

ErrCode AppendStrings(const char* nameOfFile)
{
	const char* userInput = GetUserInput;
	FILE* filePointer = OpenFile(nameOfFile, "a");

	if(NULL == userInput)
	{
		return MEM_ERROR;
	}

	if(NULL == filePointer)
	{
		free(userInput);
		return FILE_ERROR;
	}

	fwrite(userInput, sizeof(char), strlen(userInput), filePointer);
	fwrite("\n", sizeof(char), 1, filePointer)
	CloseFile(filePointer);
}

char* GetUserInput()
{
	char* buffer = NULL;
	size_t bufSize = 0;
	ssize_t size = 0;

	printf("Enter a string to append to a file");
	size = getline(&buffer, &bufSize, stdin);
	if (size < 0)
	{
		perror("Can't allocate memory for user input");
		free(buffer)
		return NULL;
	}
	buffer[size - 1] = '\0';
	return buffer;
}

ErrCode CheckSpecialCommand(const char* stringToCheck)
{

}

ErrCode Exit()
{
	return SUCCESS;
}