#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <stdio.h> /*FILES*/

int CloseFile(const char* nameOfFile);
FILE* OpenFile(const char* nameOfFile, const char* mode);
int RemoveFile(const char* nameOfFile);
int PrintNumberOfLines(const char* nameOfFile);
/*void Exit();*/
int AppendToBeginning(const char* nameOfFile, const char* buffer, size_t sizeOfBuffer;
int AppendStrings(const char* nameOfFile, const char* buffer);
char* GetUserInput();
int CheckSpecialCommand(const char* stringToCheck);
int Exit();


extern int BUFFER_SIZE = 256
extern int FILE_NAME_SIZE = 50
extern int SPECIAL_COMMAND_SIZE = 20
#endif /*__LOGGER_H__*/