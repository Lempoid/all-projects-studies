/*
Alex Breger
Review: Ben Bortkevich 19.8.24
*/

#ifndef __RESPONSIBILITY_H__
#define __RESPONSIBILITY_H__
#include <stddef.h> /*size_t*/
#include "userData.h"

typedef enum 
{
	OPERATION_SUCCESS,
    OPERATION_FAILURE,
    OPERATION_EXIT,
    OPERATION_FILE_ERROR,
    OPERATION_MEM_ERROR
}OpResult;

typedef struct 
	{
		char* stringToCompare;
		int (*CompareFunction)(UserData*,const char*);
		OpResult (*OperationFunction)(UserData* userData);
	}CommandHandler;

OpResult Chain(CommandHandler* handler, size_t handlerSize, UserData* userData);
int CompareCommands(UserData* userInput, const char* specialCommand);

#endif /*__RESPONSIBILITY_H__*/