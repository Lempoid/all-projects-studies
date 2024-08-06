#include "customStrings.h"
#include <assert.h> /*assert*/
#include <ctype.h> /*tolower*/
char *StrCpy(char *dst, const char *src)
{
	char *runner = dst;
	
	assert(NULL != dst && NULL != src);
	
	while(*src != '\0')
	{
		*runner++=*src++;
	}
	*runner = '\0';
	return (char *)dst;
}

char *StrNCpy(char *dst, const char *src, size_t dstsize)
{
	char *runner = dst;
	size_t counter = 0;
	
	assert(NULL != dst && NULL != src);
	
	while(*src != '\0')
	{
		*runner++ = *src++;
	}
	
	while(counter < dstsize)
	{
		*runner++ = '\0';
		++counter;
	}
	
	*runner = '\0';
	
	return (char *)dst;
}

int StrNCmp(const char *s1, const char *s2, size_t size)
{
	size_t counter = 0; 
	
	assert(NULL != string1 && NULL != string2);
	
	while( (*string1 == *string2) && ('\0' != *string1 && '\0' != *string2) && counter <= size)
	{
		++string2;
		++string1;
		++counter;
	}
	
	return (int *)(*string1 - *string2);
}

int StrCaseCmp(const char *s1, const char *s2)
{
	
	assert(NULL != string1 && NULL != string2);
	
	while( (tolower(*string1) == tolower(*string2)) && ('\0' != *string1 && '\0' != *string2))
	{
		++string2;
		++string1;
	}
	
	return (int *)(*string1 - *string2);
}

char *StrChr(const char *s, int c)
{
	
	assert(NULL != s);
	
	while(c != *s && '\0' != *s)
	{
		++s;
	}
	return s;
}


char *StrDup(const char *s)
{
	char *dst = (char *)calloc(strlen(s),sizeof(s));
	char *runner = dst;
	
	assert(NULL != dst && NULL != s);
	
	while(*src != '\0')
	{
		*runner++ = *src++;
	}
	
	*runner = '\0';
	
	return (char *)dst;
	
}

char *StrCat(char *dst, const char *src)
{
	
}

char *StrNCat(char *dst, const char *src, size_t srcsize);
char *StrStr(const char *haystack, const char *needle);
size_t StrSpn(const char *s, const char *accept);
char *StrTok(char *str, const char *delim);
