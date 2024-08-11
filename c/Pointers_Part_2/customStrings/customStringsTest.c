#include <stdio.h> /*printf*/
#include <string.h>
#include "customStrings.h"

int main()
{

	char StrCpy1[50] = "   Cawdaw programming";
  	char StrCpy2[50] = "Cawdaw programming";
  	char strtok1[50] = "   Cawdaw programming";
	printf("StrCmp: %d\n",StrCmp("abc","abc"));
	printf("StrCmp: %d\n",StrCmp("ABCDE","ab"));
	printf("StrCmp: %d\n",StrCmp("awdawd","aw"));
	printf("StrCmp: %d\n",StrCmp("abc","abck"));
	printf("StrCmp: %d\n",StrCmp("abc",""));
	
	printf("StrLen: %lu\n",StrLen(""));
	printf("StrLen: %lu\n",StrLen("avc"));
	printf("StrLen: %lu\n",StrLen("awdawd awdawd"));
	
	printf("StrCpy: %s\n",StrCpy(StrCpy2,StrCpy1));
	printf("StrNCpy: %s\n",StrNCpy(StrCpy2,StrCpy1, (size_t)3));
	
	printf("StrNCmp: %d\n",StrNCmp("awkawd","aw", (size_t)2));
	printf("StrCaseCmp: %d\n",StrCaseCmp("Abc","abcD"));
	printf("StrChr: %s\n",StrChr("abcdf",'b'));
	printf("StrChr: %s\n",StrChr("abcdf",'\0'));
	printf("StrDup: %s\n",StrDup("ABCD"));
	printf("StrCat: %s\n",StrCat(StrCpy2,StrCpy1));
	printf("StrNCat: %s\n",StrNCat(StrCpy2,StrCpy1,(size_t) 3));
	printf("StrStr: %s\n",StrStr("awkawd","aw"));
	printf("StrSpn: %lu\n",StrSpn("aw1kawd","a"));
	printf("StrTok:%s\n",StrTok(StrCpy1," "));
	printf("StrTokH:%s\n",strtok(strtok1," "));
/*
char *StrTok(char *str, const char *delim);
*/	
	return 0;
}
