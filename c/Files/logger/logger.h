#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <stdio.h> /*FILES*/
#include "userData.h"
#include "responsibility.h"

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
OpResult RemoveFile(UserData* userData);
OpResult PrintNumberOfLines(UserData* userData);
OpResult AppendToBeginning(UserData* userData);
ErrCode AppendStrings(UserData* userData);
char* GetUserInput();
ErrCode CheckSpecialCommand(const char* stringToCheck);
OpResult Exit(UserData* userData);


/*#define BUFFER_SIZE
#define FILE_NAME_SIZE
#define SPECIAL_COMMAND_SIZE*/
#endif /*__LOGGER_H__*/