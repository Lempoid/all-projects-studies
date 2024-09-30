#include "recursion_ex3.h"

void SortStack(stack_t* stack_to_empty, void* value)
{
    if(StackIsEmpty(stack_to_empty))
    {
        return;
    }


}

void EmptyTheStack(stack_t* to_sort)
{
    void* tmp_data;

    if(StackCapacity(to_sort) == StackSize(to_sort))
    {
        return;
    }

    

    tmp_data = StackPeek(to_sort);
    
    if( tmp_data > data )
    {
        StackPop(to_sort);
        StackPush(to_sort, data);
        StackPush(to_sort, tmp_data);
    }
}