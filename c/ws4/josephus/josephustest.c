/*
Alex Breger
Review: Ben Bortkevich 11.8.24
*/

#include <stdio.h> /*printf*/
#include "josephus.h"

int main()
{
	int const NUMBER_OF_PEOPLE = 100;
    int const KILL = 2;
    int last_person;

    last_person = Josephus(NUMBER_OF_PEOPLE, KILL);
    
    printf("The index of the last person is: %d\n", last_person);

    return 0;
}
