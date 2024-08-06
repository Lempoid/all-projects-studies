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
	//size_t count_str1 = 0;
	//size_t count_str2 = 0;
	
	assert(NULL != string1 && NULL != string2);
	
	while( (*string1 == *string2) && ('\0' != *string1 && '\0' != *string2))
	{
		++string2;
		++string1;
	}
	
	return (int *) (*string1 - *string2);
}
