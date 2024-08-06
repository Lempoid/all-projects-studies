#include <stdio.h> /*printf*/
#include "strings_reimplementation.h" /*StrLen StrCmp*/


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
	while(*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int StrCmp(const char *string1, const char *string2)
{
	size_t count_str1 = 0;
	size_t count_str2 = 0;
	
	while(string1 != '\0')
	{
		count_str1++;
	}
	
	while(string2 != '\0')
	{
		count_str2++;
	}
	
	return count_str1 - count_str2;
}
