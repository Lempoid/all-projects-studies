#include <stdio.h> /*printf*/


int main()
{
	short int shortInt;
	unsigned short int uShortInt;
	unsigned int uInt;
	int Int;
	long int lInt;
	unsigned long int uLongInt;
	signed char sChar;
	unsigned char uChar;
	float Float;
	double Double;
	long double lDouble;
	
	
	printf("Size of shortInt: %lu bytes\n", sizeof(shortInt));
    printf("Size of uShortInt: %lu bytes\n", sizeof(uShortInt));
    printf("Size of uInt: %lu bytes\n", sizeof(uInt));
    printf("Size of Int: %lu byte\n", sizeof(Int));
    printf("Size of lInt: %lu bytes\n", sizeof(lInt));
    printf("Size of uLongInt: %lu bytes\n", sizeof(uLongInt));
    printf("Size of sChar: %lu bytes\n", sizeof(sChar));
    printf("Size of uChar: %lu byte\n", sizeof(uChar));
    printf("Size of Float: %lu byte\n", sizeof(Float));
    printf("Size of Double: %lu byte\n", sizeof(Double));
    printf("Size of lDouble: %lu byte\n", sizeof(lDouble));
	
	return 0;
}
