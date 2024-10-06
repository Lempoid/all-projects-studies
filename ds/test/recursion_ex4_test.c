/*
Alex Breger
Reviewed: Chananya Templeman 6.10.24
*/
#include <stdio.h> /*printf*/
#include <string.h> /*strnvmp*/
#include "recursion_ex4.h"

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
	

	printf("StrCat: %s\n",StrCat(StrCpy2,StrCpy1));
	printf("StrStr: %s\n",StrStr("awkawd","aw"));
	printf("StrTokH:%s\n",strtok(strtok1," "));
/*
char *StrTok(char *str, const char *delim);
*/	
	return 0;
}