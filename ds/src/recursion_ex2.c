#include <stdio.h>	/*fprintf*/
#include <stdlib.h> /*free calloc*/
#include "recursion_ex1.h"

struct node
{
    struct node *next;
    int data;
};


struct node* FlipList(struct node* node)
{
    struct node *prev;
    if(NULL == node->next || NULL == node)
    {
        return node;
    }

    prev = FlipList(node->next);
    node->next->next = node;
    node->next = NULL;
    return prev;
}   