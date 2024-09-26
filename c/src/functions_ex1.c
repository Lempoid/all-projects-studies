/*
Author: Alex Breger
Reviewed: Ben Bortkevich 13.8.24
*/

#include <stdio.h> /*getchar*/
#include <stdlib.h> /*system*/
#include "keyboardCheck.h"

void UserInputCheckSwitch()
{
	char user_input;
	
	system("stty -icanon -echo");
	
	do
	{
		user_input = getchar();
		
		switch(user_input)
		{
			case 'A':
				printf("A-pressed\n");
				break;
			
			case 'T':
				printf("T-pressed\n");
				break;
		
			case 27:
				Esc();
				break;
		}
	}while(27 != user_input);
}

void UserInputCheckIfElse()
{
	char user_input;
	
	system("stty -icanon -echo");
	
	do
	{
		user_input = getchar();
		
		if('A' == user_input)
		{
			PrintA();
		}
		
		if('T' == user_input)
		{
			PrintT();
		}

		if(27 == user_input)
		{
			Esc();
		}
	}while(27 != user_input);
}

void PrintA()
{
		printf("A-pressed\n");
}

void PrintT()
{
		printf("T-pressed\n");
}

void Esc()
{
	system("stty icanon echo");
	return;
}
