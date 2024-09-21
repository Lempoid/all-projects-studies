#ifndef __STACK_H__
#define __STACK_H__

#include <stddef.h> /* For size_t  */

typedef struct stack stack_t;

/* Function to create a stack. Stack is homogenous*/
stack_t* StackCreate(size_t element_size, size_t capacity);

/* Function to destroy the stack */
void StackDestroy(stack_t* stack);

/* Function to pop an element from the stack */
void StackPop(stack_t* stack);

/* Function to push an element onto the stack */
void StackPush(stack_t* stack, void *element);

/* Function to peek the top element of the stack */
void* StackPeek(stack_t* stack);

/* Function to get the current size of the stack */
size_t StackSize(stack_t* stack);

/* Function to check if the stack is empty */
int StackIsEmpty(stack_t* stack);

/* Function to get the capacity of the stack */
size_t StackCapacity(stack_t* stack);

#endif