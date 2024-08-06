#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include "isPali.h"

int IsPali(const char *str)
{
	size_t size_str= strlen(str);
	const char *end = str + size_str - 1; /*Not needing the '\0'*/
	const char *start = str;
	
	assert(NULL != str);
	
	while(start < end)
	{
		if(tolower(*start) != tolower(*end))
		{
			return 0;
		}
		else
		{
			++start;
			--end;
		}
		return 1;
	}
}
