#include <stdio.h> /*printf*/
#include "customStrings.h"

int main()
{

	char StrCpy1[20] = "C programming";
  	char StrCpy2[20];
  	
	printf("StrCmp: %d\n",StrCmp("abc","abc"));
	printf("StrCmp: %d\n",StrCmp("ABCDE","ab"));
	printf("StrCmp: %d\n",StrCmp("abcd","abc"));
	printf("StrCmp: %d\n",StrCmp("abc","abck"));
	printf("StrCmp: %d\n",StrCmp("abc",""));
	
	printf("StrLen: %lu\n",StrLen(""));
	printf("StrLen: %lu\n",StrLen("avc"));
	printf("StrLen: %lu\n",StrLen("awdawd awdawd"));
	
	printf("StrCpy: %s\n",StrCpy(StrCpy2,StrCpy1));
	printf("StrNCpy: %s\n",StrNCpy(StrCpy2,StrCpy1, (size_t)3));
	
	printf("StrNCmp: %d\n",StrNCmp("abc","abck", (size_t)2));
	printf("StrCaseCmp: %d\n",StrCaseCmp("Abc","abcD"));
	printf("StrChr: %s\n",StrChr("abcdf",'b'));
	printf("StrDup: %s\n",StrDup("ABCD"));
		

/*
char *StrDup(const char *s);
char *StrCat(char *dst, const char *src);
char *StrNCat(char *dst, const char *src, size_t srcsize);
char *StrStr(const char *haystack, const char *needle);
size_t StrSpn(const char *s, const char *accept);
char *StrTok(char *str, const char *delim);
*/	
	return 0;
}
