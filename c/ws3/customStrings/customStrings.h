#ifndef __CUSTOMSTRINGS_H__
#define __CUSTOMSTRINGS_H__
#include <stddef.h>

char *StrCpy(char dst, const char src);
char *StrNCpy(char dst, const char src, size_t dstsize);
int StrNCmp(const char s1, const char s2, size_t size);
int StrCaseCmp(const char *s1, const char *s2);
char *StrChr(const char *s, int c);
char *StrDup(const char *s);
char *StrCat(char dst, const char src);
char *StrNCat(char dst, const char src, size_t srcsize);
char *StrStr(const char *haystack, const char *needle);
size_t StrSpn(const char *s, const char *accept);
char *StrTok(char str, const char delim);

#endif
