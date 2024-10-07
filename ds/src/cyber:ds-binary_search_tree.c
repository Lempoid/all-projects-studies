#include <stdlib.h> /*calloc*/
#include <stdio.h> /*fprintf*/
#include "cyber:ds-binary_search_tree.h"

struct bst
{
    void* data;
    bst_t* left;
    bst_t* right;
    action_function_t action_function;
    compare_func_t compare_function;    
};

typedef int (*action_function_t)(void *data, void *parameter);

typedef int (*compare_func_t)(const void *data1, const void *data2);

bst_t *BstCreate(compare_func_t cmp_func)
{
    bst_t* bst = malloc(sizeof(bst_t));

    if(NULL == bst)
    {
        fprintf(stderr, "Wasn't able to create a binary search tree.\
        Returning NULL.\n");
        return NULL;
    }

    bst->compare_function = cmp_func;
    bst->action_function = NULL;
    bst->left = NULL;
    bst->right = NULL;
    bst->data = 0;
    return bst;
}

void BstDestroy(bst_t *bst)
{
    if(NULL == bst->left && NULL == bst->right)
    {
        free(bst);
        return;
    }

    BstDestroy(bst->left);
    BstDestroy(bst->right);
    free(bst);
}

void BstRemove(bst_t *bst,const void *data)
{

}

int BstInsert(bst_t *bst, void *data)
{
    if(bst->compare_function(*(int*)bst->data,*(int*)data))
    {
        if(NULL == bst->left)
        {
            bst_t* node = malloc(sizeof(bst_t));
            node->compare_function = bst->compare_function;
            node->action_function = NULL;
            node->left = NULL;
            node->right = NULL;
            node->data = data;

            bst->left = node;
            
            return 1;
        }
        else
        {
            BstInsert(bst->left, data);
        }
    }
    else
    {
        if(NULL == bst->right)
        {
            bst_t* node = malloc(sizeof(bst_t));
            node->compare_function = bst->compare_function;
            node->action_function = NULL;
            node->left = NULL;
            node->right = NULL;
            node->data = data;

            bst->right = node;
            
            return 1;
        }
        else
        {
            BstInsert(bst->right, data);
        }
    }

    return 0;
}

size_t BstSize(const bst_t *bst)
{
    if(NULL == bst->left && NULL == bst->right)
    {
        return 1;
    }
    return 1 + BstSize(bst->left) + BstSize(bst->right);
}

int BstIsEmpty(const bst_t *bst);

void *BstFind(bst_t *bst, const void *data);

int BstForEach(bst_t *bst, action_function_t action_func, void *param);


