#include <assert.h> /*assert*/
#include <ctype.h> /*tolower*/
#include <stdlib.h> /*calloc malloc*/
#include "customStrings.h"

size_t StrLen(const char *str)
{
	size_t count = 0;
	
	assert(NULL != str);
	
	while('\0' != *str)
	{
		++count;
		++str;
	}
	return count;
}

int StrCmp(const char *string1, const char *string2)
{
	
	assert(NULL != string1 && NULL != string2);
	
	while( (*string1 == *string2) && ('\0' != *string1 && '\0' != *string2))
	{
		++string2;
		++string1;
	}
	
	return (int) (*string1 - *string2);
}

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
	
	while(*src != '\0' && counter < dstsize)
	{
		*runner++ = *src++;
		++counter;
	}
	
	while(counter < dstsize)
	{
		*runner++ = '\0';
		++counter;
	}
	
	*runner = '\0';
	
	return (char *)dst;
}

int StrNCmp(const char *string1, const char *string2, size_t size)
{
	
	assert(NULL != string1 && NULL != string2);
	
	while( (*string1 == *string2) && (0 < size - 1) && ('\0' != *string1 && '\0' != *string2))
	{
		++string2;
		++string1;
		--size;
	}
	
	return (int)(*string1 - *string2);
}

int StrCaseCmp(const char *string1, const char *string2)
{
	
	assert(NULL != string1 && NULL != string2);
	
	while( (tolower(*string1) == tolower(*string2)) && ('\0' != *string1 && '\0' != *string2))
	{
		++string2;
		++string1;
	}
	
	return (int)(*string1 - *string2);
}

char *StrChr(const char *s, int c)
{
	
	assert(NULL != s);
	
	while(c != *s && '\0' != *s)
	{
		++s;
	}
	
	if('\0' == *s)
	{
		return NULL;
	}
	
	return (char*)s;
}


char *StrDup(const char *src)
{
	
	char *dst = (char *)calloc(StrLen(src),sizeof(src));
	char *runner = dst;
	
	assert(NULL != src && NULL != dst);
	
	while('\0' != *src)
	{
		*runner++ = *src++;
	}
	
	*runner = '\0';
	
	return (char *)dst;
	
}

char *StrCat(char *dst, const char *src)
{

	char *runner = dst + StrLen(dst);
	
	assert(NULL != dst && NULL != src);
		
	while ('\0' !=  *src) 
	{
		*runner++ = *src++;
	}
	
	*runner = '\0';
	
	return (char*)dst;
}

char *StrNCat(char *dst, const char *src, size_t srcsize)
{
	
	char *runner = dst + StrLen(dst);
		
	assert(NULL != dst && NULL != src);
		
	while ('\0' != *src && 0 < srcsize) 
	{
		*runner++ = *src++;
		--srcsize;
	}
	
	*runner = '\0';
	
	return (char*)dst;
}

char *StrStr(const char *haystack, const char *needle)
{
	
	assert(NULL != haystack && NULL != needle);
	
	if('\0' == *needle)
	{
		return (char*)haystack;
	}
	
	while('\0' != *haystack)
	{
		if(0 == StrNCmp(haystack, needle, StrLen(needle)))
		{
			return (char*)haystack;
		}
		++haystack;
	}
	
	return NULL;
}
size_t StrSpn(const char *s, const char *accept)
{
	
	size_t count = 0;
	
	assert(NULL != s && NULL != accept);
	
	while('\0' != *s)
	{
		if(NULL != StrChr(accept, (int)*s))
		{
			++count;
			++s;
		}
		else
		{
			break;
		}
	}
	
	return (size_t)count;
}

char *StrTok(char *str, const char *delim)
{

	static char* origin_string = NULL;
	/*char* return_str = (char*)malloc(sizeof(char) * 1);*/
	char* return_str = NULL;
	
	assert(NULL != delim);
			
	if(NULL != str)
	{
		origin_string = str;
	}

	while(NULL != StrChr(delim, (char)*origin_string))
	{
		*origin_string = '\0';
		++origin_string;
		++str;
	}
	
	while(NULL != origin_string && NULL == StrChr(delim, (int)*origin_string))
	{
		*(return_str + StrLen(return_str) - 1) = *origin_string;
		return_str = (char*)realloc(return_str, sizeof(return_str) * StrLen(return_str) + 1);
	}
	
	*(return_str + StrLen(return_str) - 1) = '\0';
	
	return (char*)return_str; /*How to free it?*/
	
}
