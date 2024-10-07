#ifndef __BST_H__
#define __BST_H__

#include <stddef.h> /* size_t */

typedef struct bst bst_t;

typedef int (*action_function_t)(void *data, void *parameter);

typedef int (*compare_func_t)(const void *data1, const void *data2);

bst_t *BstCreate(compare_func_t cmp_func);

void BstDestroy(bst_t *bst);

void BstRemove(bst_t *bst,const void *data);

int BstInsert(bst_t *bst, void *data);

size_t BstSize(const bst_t *bst);

int BstIsEmpty(const bst_t *bst);

void *BstFind(bst_t *bst, compare_func_t cmp_func, const void *data);

int BstForEach(bst_t *bst, action_function_t action_func, void *param);


#endif /*__BST_H__*/