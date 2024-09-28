#include <stdio.h>
#include "/home/lempo/git/ds/include/slist.h"

int main() 
{
    slist_t *list;
    slist_iter_t iter;
    slist_iter_t iter2; 
    slist_iter_t iter3;
    int a = 10;
    int b = 20;
    int c = 30;

    list = SListCreate();
    if (NULL != list) 
    {
        printf("List created.\n");
    } 
    else 
    {
        printf("Failed to create list.\n");
    }

    if (1 == SListIsEmpty(list)) 
    {
        printf("List is empty after initialization.\n");
    } 
    else 
    {
        printf("List is not empty after initialization.\n");
    }

    iter = SListInsert(list, SListEnd(list), &a);
    iter2 = SListInsert(list, SListEnd(list), &b);
    iter3 = SListInsert(list, SListEnd(list), &c);
    printf("Inserted %d, %d, %d into the list.\n",*(int*)SListGetData(iter),*(int*)SListGetData(iter2),*(int*)SListGetData(iter3));

    if (0 == SListIsEmpty(list)) 
    {
        printf("List is not empty after insertions.\n");
    } 
    else 
    {
        printf("List is empty after insertion.\n");
    }

    printf("List count: %lu\n", SListCount(list));

    printf("First element: %d\n", *(int*)SListGetData(iter));
    printf("Second element: %d\n", *(int*)SListGetData(iter2));
    printf("Third element: %d\n", *(int*)SListGetData(iter3));

    printf("Iterating through the list: "); 
    iter = SListBegin(list);
    while (iter != SListEnd(list)) 
    {
        printf("%d ", *(int*)SListGetData(iter));
        iter = SListNext(iter);
    }
    
    printf("\n");

    SListRemove(iter2);
    printf("Removed second element: %d.\n", *(int*)SListGetData(iter2));

    printf("List after removal: ");
    iter = SListBegin(list);
    while (iter != SListEnd(list)) 
    {
        printf("%d ", *(int*)SListGetData(iter));
        iter = SListNext(iter);
    }
    
    printf("\n");

    SListDestroy(list);
    printf("List destroyed.\n");
    
    
    return 0;
}