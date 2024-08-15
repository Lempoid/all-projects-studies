#include <stdio.h>
#include "logger.h"

void CloseFile(FILE* file)
{
	fclose(file);
}

FILE* OpenFile(const char* nameOfFile, const char* mode)
{
	char* filePointer = fopen(nameOfFile, mode);
	
	if(!filePointer)
	{
		printf("FileOpening failed.");
		return ERROR;
	}

	return filePointer;
}

void RemoveFile(const char* nameOfFile)
{
	/*FILE* filePtr = OpenFile(nameOfFile, "r");
	CloseFile(filePtr);*/
	unlink(nameOfFile);
}

void PrintNumberOfLines(const char* nameOfFile)
{
	size_t count;
	char c;
	FILE* filePtr = OpenFile(nameOfFile, "r");
	while(!feof(filePtr))
	{
		c = fgetc(filePtr);
		if('\n' == c)
		{
			++count;
		}
	}

	printf("The number of lines is: %d", count);
	CloseFile(filePtr);
}

void AppendToBeginning(const char* nameOfFile)
{
	char byteToRead;

	FILE* originalFile = OpenFile(nameOfFile,"rb");
	FILE* tmpFile = OpenFile("tmpFile","ab");

	while(!feof(originalFile))
	{
		fread(&byteToRead, sizeof(char), 1, originalFile);
		fwrite(&byteToRead, sizeof(char), 1, tmpFile);
	}
	
	/*buffer = buffer + 1;
	sizeOfBuffer = sizeOfBuffer - 1;
	size_t originalFileSize;
	char* bufferOrignalFile;
	FILE* filePtr = OpenFile(nameOfFile, "r");
	
	fseek(filePtr, 0, SEEK_END);
	originalFileSize = ftell(filePtr);
	fseek(filePtr, 0, SEEK_SET);

	bufferOriginalFile = malloc(originalFileSize + 1);
	fread(bufferOriginalFile,1,originalFileSize,filePtr);
	bufferOriginalFile[originalFileSize] = '\0';
	CloseFile(filePtr);

	filePtr = OpenFile(nameOfFile, "w");
	fputs(buffer,filePtr);
	fputs(bufferOriginalFile,filePtr);
	CloseFile(filePtr);

	free(bufferOriginalFile);*/
}

void AppendStrings(const char* nameOfFile)
{
	FILE* filePtr = OpenFile(nameOfFile, "a");
	const char* userInput = GetUserInput;
	fprintf(filePtr, userInput);
	CloseFile(filePtr);
}

char* GetUserInput(const char* nameOfFile)
{
	const char* buffer = NULL;
	size_t bufSize = 0;
	size_t size = 0;

	printf("Enter a string to append to a file");
	getline(&buffer, &bufSize, stdin);
	if (size < 0)
	{
		printf("Can't allocate memory for user input");

	}
	if(!buffer)
	{
		printf("Can't allocate memory for user input");
		return NULL;
	}
	return buffer;
}

int CheckSpecialCommand(const char* stringToCheck)
{

}

int Exit()
{
	
}