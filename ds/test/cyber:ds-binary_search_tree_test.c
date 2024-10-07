#include <stdio.h> /*printf*/
#include "cyber:ds-binary_search_tree.h"

typedef int (*action_function_t)(void *data, void *parameter);

int CompareFunc(const void* data1, const void* data2)
{
    return *(int*)data1 - *(int*)data2;
}

int main()
{
    int a = 6;
    int b = 10;
    int c = 4;
    int d = 3;
    int e = 9;
    compare_func_t CompareFunction = CompareFunc;

    printf("Creating BST\n");
    bst_t* tree = BstCreate(CompareFunction);
    
    if(NULL == tree)
    {
        fprintf(stderr, "Creation of BST failed.\n");
    }
    else
    {
        printf("BST created.\n");
    }
    
    printf("Inserting %d.\n", a);
    BstInsert(tree, &a);
    printf("Inserting %d.\n", b);
    BstInsert(tree, &b);
    printf("Inserting %d.\n", c);
    BstInsert(tree, &c);
    printf("Inserting %d.\n", d);
    BstInsert(tree, &d);
    printf("Inserting %d.\n", e);
    BstInsert(tree, &e);
    
    printf("Printing size: ");
    printf("%lu.\n", BstSize(tree));
    
    printf("Removing %d\n", b);
    BstRemove(tree, &b);

    printf("Printing size: ");
    printf("%lu.\n", BstSize(tree));

/*
void BstDestroy(bst_t *bst);

void BstRemove(bst_t *bst,const void *data);

int BstInsert(bst_t *bst, void *data);

size_t BstSize(const bst_t *bst);

int BstIsEmpty(const bst_t *bst);

void *BstFind(bst_t *bst, compare_func_t cmp_func, const void *data);

int BstForEach(bst_t *bst, action_function_t action_func, void *param);

*/

    return 0;
}

