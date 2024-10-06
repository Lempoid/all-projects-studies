/*
Alex Breger
Reviewed: Chananya Templeman 6.10.24
*/

#include <assert.h> /*assert*/
#include <string.h> /*strncmp*/
#include "recursion_ex4.h"

size_t StrLen(const char *str)
{
	if('\0' == *str)
    {
        return 1;
    }
    
	return 1 + StrLen(++str);
}

int StrCmp(const char *string1, const char *string2)
{
	
	if((*string1 != *string2) || ('\0' == *string1 || '\0' == *string2))
	{
		return (int) (*string1 - *string2);
	}
    
	return StrCmp(++string1,++string2);
}

char *StrCat(char *dst, const char *src)
{

	if('\0' != *dst)
	{
		StrCat(dst + 1, src);
	}
	else
	{
		while('\0' != *src)
		{
			*dst = *src;
			++dst;
			++src;
		}

		*dst = '\0';
	}

	return dst;
}

char *StrStr(const char *haystack, const char *needle)
{
		
	if('\0' == *needle)
	{
		return (char*)haystack;
	}

	if('\0' == *haystack)
	{
		return NULL;
	}
	
	if(0 == strncmp(haystack, needle, StrLen(needle)))
		{
			return (char*)haystack;
		}
	
	return StrStr(haystack + 1, needle);
}

char *StrCpy(char *dst, const char *src)
{
	
	if('\0' == *src)
	{
		*dst = '\0';
		return dst;
	}

	*dst = *src;

	StrCpy(dst + 1, src + 1);

	return dst;
}