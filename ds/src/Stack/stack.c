#include <stddef.h>
#include <errno.h>
#include <stdio.h>
#include "stack.h"

struct stack 
{
    void* array;
    int top;
    size_t capacity;
    size_t element_size;
};

/* Function to create a stack. Stack is homogenous*/
stack_t* StackCreate(size_t element_size, size_t capacity)
{
    stack_t* stack = calloc(1,sizeof(stack_t));
    if(NULL == stack)
    {
        fprintf(stderr, "Can't create stack, returning null\n");
        return NULL;
    }
    stack->array = (void*)calloc(capacity,element_size);
    if(NULL == stack->array)
    {
        free(stack);
        fprintf(stderr, "Can't create stack, returning null.\n");
        return NULL;
    }
    stack->capacity = capacity;
    stack->element_size = element_size;
    stack->top = -1;

    return stack;
}

/* Function to destroy the stack */
void StackDestroy(stack_t *stack)
{
    if(NULL == stack)
    {
        fprintf(stderr, "Stack is null.\n");
        return;
    }

    free(stack->array);
    free(stack);
    
    stack->array = NULL;
    stack = NULL;
}

/* Function to pop an element from the stack */
void StackPop(stack_t *stack)
{
    if(NULL == stack)
    {
        fprintf(stderr, "Stack is null.\n");
        return;
    }

    if(-1 == stack->top)
    {
        fprintf(stderr, "Stack is empty.\n");
        return;
    }

    stack->top -= 1;
}

/* Function to push an element onto the stack */
void StackPush(stack_t *stack, void *element)
{
    if(NULL == stack)
    {
        fprintf(stderr, "Error: Stack is NULL\n");
        return;
    }
    
    if(NULL == element)
    {
        fprintf(stderr, "Element is NULL, returning.\n");
        return;
    }

    if(stack->top >= stack->capacity - 1)
    {
        fprintf(stderr, "Stack is full.\n");
        return;
    }

    stack->top += 1;
    memcpy((char*)stack->array + (stack->top * stack->element_size), element, stack->element_size);
}

/* Function to peek the top element of the stack */
void* StackPeek(stack_t *stack)
{
    if(NULL == stack)
    {
        fprintf(stderr, "Stack is null. Returning null. \n");
        return NULL;
    }

    if(-1 == stack->top)
    {
        fprintf(stderr, "Stack is empty.\n");
        return NULL;
    }

    
    return (char*)(stack->array + (stack->top * stack->element_size));
}

/* Function to get the current size of the stack */
size_t StackSize(stack_t *stack)
{
    if(NULL == stack)
    {
        fprintf(stderr, "Stack is null. Returning 0. \n");
        return 0;
    }

    return stack->top + 1;
}

/* Function to check if the stack is empty */
int StackIsEmpty(stack_t *stack)
{
    if(NULL == stack)
    {
        fprintf(stderr, "Stack is null. Returning 0. \n");
        return 0;
    }

    if(-1 == stack->top)
    {
        return 1;
    }
    
    return 0;
}

/* Function to get the capacity of the stack */
size_t StackCapacity(stack_t *stack)
{
    if(NULL == stack)
    {
        fprintf(stderr, "Stack is null. Returning 0. \n");
        return 0;
    }

    return stack->capacity;
}