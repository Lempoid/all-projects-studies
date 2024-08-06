// Alex Breger
// Code Review Ben Bortkevich 6.8.24

#include "strings_reimplementation.h" /*StrLen StrCmp*/
#include <assert.h> /*assert*/

int main()
{
const char *string1 = "abc";
const char *string2 = "abc";
const char *string3 = "acd";

return 0;
}

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
	size_t count_str1 = 0;
	size_t count_str2 = 0;
	
	assert(NULL != string1 && NULL != string2);
	
	while('\0' != *string1)
	{
		++count_str1;
	}
	
	while('\0' != *string2)
	{
		++count_str2;
	}
	
	return count_str1 - count_str2;
}
