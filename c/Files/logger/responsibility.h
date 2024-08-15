#ifndef __RESPONSIBILITY_H__
#define __RESPONSIBILITY_H__

void Chain(const char* specialCommand);
int CompareCommands(const char* specialCommand, const char* userInput);

struct responsibility
	{
		char* stringToCompare;
		int (*CompareFunction)(char*, char*);
		void (*OperationFunction)(const char*);
	};
	
#endif /*__RESPONSIBILITY_H__*/