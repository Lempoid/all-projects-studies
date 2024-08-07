#include <stdio.h> /*printf*/
#include "isPali.h" /*IsPali*/

void Print(const char* str);

int main()
{
	const char* str = "abba";
	const char* str2 = "dad";
	const char* str3 = "kip";
	const char* str4 = "awdaww";
	const char* str5 = "!d@d!";
	
	Print(str);
	Print(str2);
	Print(str3);
	Print(str4);
	Print(str5);
	
	return 0;
}

void Print(const char* str)
{
	printf("%s: %d\n",str, IsPali(str));
}
