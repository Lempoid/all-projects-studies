#include "josephus.h"

int Josephus(int const NUMBER_OF_PEOPLE, int const KILL) {
    int index = 0;
	int i;
	
    for (i = 2; i <= NUMBER_OF_PEOPLE; i++) {
        index = (index + KILL) % i;
    }

    return index;
}

