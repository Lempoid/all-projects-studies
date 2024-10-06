/*
Alex Breger
Reviewed: Chananya Templeman 6.10.24
*/

#include "recursion_ex3.h"

void SortStack(stack_t* to_sort, void* value)
{
    void* tmp;
    if(StackIsEmpty(to_sort) || *(int*)value > *(int*)StackPeek(to_sort))
    {
        StackPush(to_sort, value);

        return;
    }
    
    tmp = StackPeek(to_sort);

    StackPop(to_sort);

    SortStack(to_sort, value);

    StackPush(to_sort, tmp);
}

void EmptyTheStack(stack_t* stack_to_empty)
{
    void* tmp_data;

    if(StackIsEmpty(stack_to_empty))
    {
        return;
    }    

    tmp_data = StackPeek(stack_to_empty);
    
    StackPop(stack_to_empty);

    EmptyTheStack(stack_to_empty);

    SortStack(stack_to_empty, tmp_data);
}