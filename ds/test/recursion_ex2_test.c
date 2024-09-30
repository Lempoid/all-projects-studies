#include <stdio.h>
#include <stdlib.h>
#include "recursion_ex2.h"

struct node
{
    struct node *next;
    int data;
};


int main()
{
    struct node *node1 = malloc(sizeof(struct node));
    struct node *node2 = malloc(sizeof(struct node));
    struct node *node3 = malloc(sizeof(struct node));
    struct node *reverse;
    node1->data = 1;
    node1->next = node2;
    node2->data = 2;
    node2->next = node3;    
    node3->data = 3;
    node3->next = NULL;
    reverse = node1;
    printf("Before\n");

     while (node1 != NULL)
    {
        printf("+\n");
        printf("%d\n",node1->data);
        node1 = node1->next;
        printf("-\n");
    }
    node1 = reverse;
    reverse = FlipList(node1);
    printf("After\n");

    node1->next = NULL;


    while (reverse != NULL)
    {
        printf("%d\n",reverse->data);
        reverse = reverse->next;
    }
    
    return 0;
}
