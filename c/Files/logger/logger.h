#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <stdio.h> /*FILES*/

void CloseFile(const char* nameOfFile);
FILE* OpenFile(const char* nameOfFile, const char* mode);
void RemoveFile(const char* nameOfFile);
void PrintNumberOfLines(const char* nameOfFile);
/*void Exit();*/
void AppendToBeginning(const char* nameOfFile, const char* buffer, size_t sizeOfBuffer;
void AppendStrings(const char* nameOfFile, const char* buffer);
#endif /*__LOGGER_H__*/