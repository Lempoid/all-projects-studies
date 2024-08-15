#include "logger.h"

void CloseFile(FILE* file)
{
	fclose(file);
}

FILE* OpenFile(const char* nameOfFile, const char* mode)
{
	char* filePointer = fopen(nameOfFile, mode);
	
	if(!filePtr)
	{
		printf("FileOpening failed.");
		return NULL;
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

void AppendToBeginning(const char* nameOfFile, char* buffer, size_t sizeOfBuffer)
{
	buffer = buffer + 1;
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

	free(bufferOriginalFile);

}

void AppendStrings(const char* nameOfFile,char* buffer, size_t sizeOfBuffer)
{
	FILE* filePtr = OpenFile(nameOfFile, "a");
	fgets(buffer, sizeOfBuffer, stdin);
	fprintf(filePtr, *buffer);
	CloseFile(filePtr);
}