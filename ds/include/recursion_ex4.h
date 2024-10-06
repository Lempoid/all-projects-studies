/*
Alex Breger
Reviewed: Chananya Templeman 6.10.24
*/

#ifndef __RECURSION_EX4_H__
#define __RECURSION_EX4_H__

#include <stddef.h> /*size_t*/

int StrCmp(const char *str1, const char *str2);
size_t StrLen(const char *str);
char *StrCat(char *dst, const char *src);
char *StrCpy(char *dst, const char *src);
char *StrStr(const char *haystack, const char *needle);

#endif /*__RECURSION_EX4_H__*/