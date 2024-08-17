#include <stddef.h> /*size_t*/
#include <string.h>
#include <stdlib.h> /*free*/
#include <stdio.h> /*getline*/
#include "logger.h"
#include "userData.h"
#include "responsibility.h"

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

OpResult RemoveFile(UserData* userData)
{
	OpResult errorResult = OPERATION_SUCCESS;

	if(0 != remove(userData->fileName))
	{
		perror("File removal failed.\n");
		errorResult = OPERATION_FILE_ERROR;
	}

	return errorResult;
}

OpResult PrintNumberOfLines(UserData* userData)
{
	size_t count = 0;
	char charToRead;
	FILE* filePointer = OpenFile(userData->fileName, "r");

	if(NULL == filePointer)
	{
		return OPERATION_FILE_ERROR;
	}

	do
	{
		charToRead = fgetc(filePointer);
		
		if('\n' == charToRead)
		{
			++count;
		}

	}while(!feof(filePointer));

	printf("The number of lines is: %lu\n", count);
	
	CloseFile(filePointer);
	
	return OPERATION_SUCCESS;
}

OpResult AppendToBeginning(UserData* userData)
{
	char byteToRead;
	UserData tmpUserData;

	FILE* originalFile = OpenFile(userData->fileName,"rb");
	FILE* tmpFile = OpenFile("tmpFile","ab");

	if(NULL == originalFile)
	{
		perror("Can't open the files in AppendToBeginning");
		CloseFile(originalFile);
		return OPERATION_FILE_ERROR;
	}

	if(NULL == tmpFile)
	{
		perror("Can't open the files in AppendToBeginning");
		CloseFile(tmpFile);
		return OPERATION_FILE_ERROR;
	}

	fwrite(userData->userInput, sizeof(char), strlen(userData->userInput), originalFile);
	fwrite("\n", sizeof(char), 1, originalFile);

	while(!feof(originalFile))
	{
		fread(&byteToRead, sizeof(char), 1, originalFile);
		fwrite(&byteToRead, sizeof(char), 1, tmpFile);
	}
	
	CloseFile(originalFile);
	CloseFile(tmpFile);
	
    if (RemoveFile(userData) != OPERATION_SUCCESS) 
    {
        return OPERATION_FILE_ERROR;
    }

    if (rename("tmpFile", userData->fileName) != 0) 
    {
        perror("Failed to rename the temporary file");
        tmpUserData.fileName = "tmpFile";
        RemoveFile(&tmpUserData);
        return OPERATION_FILE_ERROR;
    }

    return OPERATION_SUCCESS;
	
}

ErrCode AppendStrings(UserData* userData)
{
	FILE* filePointer = OpenFile(userData->fileName, "a");

	if(NULL == filePointer)
	{
		return FILE_ERROR;
	}

	fwrite(userData->userInput, sizeof(char), strlen(userData->userInput), filePointer);
	fwrite("\n", sizeof(char), 1, filePointer);
	CloseFile(filePointer);

	return SUCCESS;
}

char* GetUserInput()
{
	char* buffer = NULL;
	size_t bufSize = 0;
	int size = 0;

	printf("Enter a string to append to a file\n");
	size = getline(&buffer, &bufSize, stdin);
	if (size < 0)
	{
		perror("Can't allocate memory for user input");
		free(buffer);
		return NULL;
	}
	buffer[size - 1] = '\0';
	return buffer;
}

OpResult Exit(UserData* userData)
{
	return OPERATION_EXIT;
}