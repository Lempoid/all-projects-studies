#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <stdio.h> /*FILES*/

typedef enum 
{
	ERROR, 
	SUCCESS, 
	NO_FILE,
	FILE_ERROR,
	MEM_ERROR
} ErrCode;

ErrCode CloseFile(FILE* nameOfFile);
FILE* OpenFile(const char* nameOfFile, const char* mode);
ErrCode RemoveFile(const char* nameOfFile);
ErrCode PrintNumberOfLines(const char* nameOfFile);
/*void Exit();*/
ErrCode AppendToBeginning(const char* nameOfFile);
ErrCode AppendStrings(const char* nameOfFile);
char* GetUserInput();
ErrCode CheckSpecialCommand(const char* stringToCheck);
ErrCode Exit();


/*#define BUFFER_SIZE
#define FILE_NAME_SIZE
#define SPECIAL_COMMAND_SIZE*/
#endif /*__LOGGER_H__*/