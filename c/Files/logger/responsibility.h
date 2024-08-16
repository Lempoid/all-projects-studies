#ifndef __RESPONSIBILITY_H__
#define __RESPONSIBILITY_H__

typedef enum 
{
	OPERATION_SUCCESS,
	OPERATION_FAILURE,
	OPERATION_EXIT,
	OPERATION_FILE_ERROR
}OpResult;

typedef struct 
	{
		char* stringToCompare;
		int (*CompareFunction)(char*, char*);
		OpResult (*OperationFunction)(const char*);
	}CommandHandler;

OpResult Chain(const char* specialCommand, CommandHandler* handler, size_t handlerSize, const char* fileName);
int CompareCommands(const char* userInput, const char* specialCommand);

#endif /*__RESPONSIBILITY_H__*/