#include <stdlib.h>

int main()
{
const char * str1 = NULL;  /*0*/
char const * str2;         /*1*/
char * const str3 = NULL;  /*2*/
char* str4 = NULL;         /*3*/
char* const str5;          /*4*/

str1 = str2; /*5*/
str2 = str3; /*6*/
str4 = str3; /*7*/
str3 = str4; /*8*/
str2 = str4; /*9*/
str4 = str2; /*10*/
str5 = str4; /*11*/

}
