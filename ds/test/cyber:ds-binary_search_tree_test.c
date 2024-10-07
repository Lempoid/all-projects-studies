#include <stdio.h> /*printf*/
#include "cyber:ds-binary_search_tree.h"

typedef int (*action_function_t)(void *data, void *parameter);

typedef int (*compare_func_t)(const void *data1, const void *data2);

int CompareFunc(const void* data1, const void* data2)
{
    return *(int*)data1 - *(int*)data2;
}
int main()
{
    printf("Creating BST\n");
    bst_t* tree = BstCreate(CompareFunc);
    if(NULL == tree)
    {
        fprintf(stderr, "Creation of BST failed.\n");
    }
    else
    {
        printf("BST created.\n");
    }
    
    printf("Inserting 6.\n");
    BstInsert(tree, 6);
    printf("Inserting 10.\n");
    BstInsert(tree, 10);
    printf("Inserting 4.\n");
    BstInsert(tree, 4);
    printf("Inserting 3.\n");
    BstInsert(tree, 3);
    printf("Inserting 9.\n");
    BstInsert(tree, 9);

    printf("Printing size %lu.\n", BstSize(tree));
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

