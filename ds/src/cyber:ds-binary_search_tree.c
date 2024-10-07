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

static bst_t* GoToMostLeftLeaf(bst_t* tree)
{
    if(NULL == tree->left && NULL == tree->right)
    {
        return tree;
    }

    GoToMostLeftLeaf(tree->left);
}

static bst_t* GoToMostRightLeaf(bst_t* tree)
{
    if(NULL == tree->left && NULL == tree->right)
    {
        return tree;
    }

    GoToMostRightLeaf(tree->right);
}

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
    bst->data = NULL;
    return bst;
}

void BstDestroy(bst_t *bst)
{
    if(NULL == bst->left && NULL == bst->right)
    {
        free(bst);
        bst = NULL;
        return;
    }

    BstDestroy(bst->left);
    BstDestroy(bst->right);
    free(bst);
    bst = NULL;
}

void BstRemove(bst_t *bst,const void *data)
{
    printf("in bst remove");
    bst_t* replacer_node;
    int compare_result;

    if(NULL == bst || NULL == bst->data)
    {
        return;
    }
    
    printf("before compare");
    compare_result = bst->compare_function(bst->data, data);

    if(0 == compare_result)
    {
        if(NULL == bst->left && NULL == bst->right)
        {
            free(bst);
            bst = NULL;
        }
        else if(bst->right)
        {
            replacer_node = GoToMostLeftLeaf(bst->right);
        }
        else
        {
            replacer_node = GoToMostRightLeaf(bst->left);
        }

        bst->data = replacer_node->data;
        free(replacer_node);
        replacer_node = NULL;
    } 
    else if(compare_result < 0)
    {
        BstRemove(bst->right, data);  
    }
    else
    {
        BstRemove(bst->left, data);
    }
}

int BstInsert(bst_t *bst, void *data)
{
    int compare_result;

    if (NULL == bst)
    {
        return 0;
    }

    if (NULL == bst->data)
    {
        bst->data = data;
        return 1;
    }

    compare_result = bst->compare_function(bst->data, data);

    if (0 == compare_result)
    {
        return 0;
    }
    else if(compare_result > 0)
    {
        if(NULL == bst->left)
        {
            bst->left = BstCreate(bst->compare_function);
            bst->left->data = data;
            return 1;
        }
        else
        {
            return BstInsert(bst->left,data);
        }
    }
    else
    {
        if(NULL == bst->right)
        {
            bst->right = BstCreate(bst->compare_function);
            bst->right->data = data;
            return 1;
        }
        else
        {
            return BstInsert(bst->right,data);
        }
    }
}

size_t BstSize(const bst_t *bst)
{
    if(NULL == bst)
    {
        return 0;
    }

    if(NULL == bst->left && NULL == bst->right)
    {
        return 1;
    }
    return 1 + BstSize(bst->left) + BstSize(bst->right);
}

int BstIsEmpty(const bst_t *bst)
{
    if(NULL == bst)
    {
        return 1;
    }

    return 0;
}

void *BstFind(bst_t *bst, const void *data)
{
    int compare_result;

    if(NULL == bst)
    {
        return NULL;
    }
    
    compare_result = bst->compare_function(bst->data, data);

    if(0 == compare_result)
    {
        return bst->data;
    } 
    else if(compare_result < 0)
    {
        BstFind(bst->right, data);  
    }
    else
    {
        BstFind(bst->left, data);
    }
}

int BstForEach(bst_t *bst, action_function_t action_func, void *param)
{

}


