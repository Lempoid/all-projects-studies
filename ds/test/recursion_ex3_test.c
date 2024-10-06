/*
Alex Breger
Reviewed: Chananya Templeman 6.10.24
*//*
Alex Breger
Reviewed: Chananya Templeman 6.10.24
*/

#include <stdio.h> /*printf*/
#include "recursion_ex3.h"

int main()
{
    stack_t* stack = StackCreate(sizeof(int), 4);
    StackPush(stack,(int*)5);
    StackPush(stack,(int*)4);
    StackPush(stack,(int*)2);
    StackPush(stack,(int*)1);


    EmptyTheStack(stack);

    while(!StackIsEmpty(stack))
    {
        printf("%d\n", *(int*)StackPeek(stack));
        StackPop(stack);
    }
    return 0;
}
