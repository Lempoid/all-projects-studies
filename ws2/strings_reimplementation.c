#include <stdlib.h>
#include <stdio.h>
#include "strings_reimplementation.h"


int main()
{
const char *string1 = "abc";
const char *string2 = "abc";
const char *string3 = "acd";

return 0;
}

size_t StrLen(const char *string_to_check_length)
{
	size_t count = 0;
	while(*string_to_check_length != '\0')
	{
		count++;
		string_to_check_length++;
	}
	return count;
}

int StrCmp(const char *string1, const char *string2)
{
	size_t string1_size = StrLen(string1);
	size_t string2_size = StrLen(string2);
	
	if(string1_size != string2_size)
	{
		return 0;
	}
	else
	{
		while(*string1 != '\0')
			{
				if(*string1 != *string2)
				{
					return 0;
				}
				string1++;
				string2++;
			}
	}
	
	return 1;
}
