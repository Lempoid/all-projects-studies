/*
Binary Search Tree implementaion.

Alex Breger
Reviwed: Ben Bortkevich 8.10.24
*/

#include <stdio.h> /*printf*/
#include "cyber:ds-binary_search_tree.h"


int Multiply(void *data, void *parameter)
{
    return *(int*)data * *(int*)parameter;
}

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
    int f = 2;

    compare_func_t CompareFunction = CompareFunc;

    printf("Creating BST\n");
    bst_t* tree = BstCreate(CompareFunction);
    
    if(BstIsEmpty(tree))
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
    
    if(BstIsEmpty(tree))
    {
        fprintf(stderr, "BST is empty after insertion.\n");
    }
    else
    {
        printf("BST insertion succeeded.\n");
    }

    printf("Printing size: ");
    printf("%lu.\n", BstSize(tree));
    
    printf("Printing the tree.\n");
    PrintTree(tree);

    printf("Removing %d\n", b);
    BstRemove(tree, &b);

    printf("Printing size: ");
    printf("%lu.\n", BstSize(tree));

    printf("Doing for each.\n");
    BstForEach(tree,Multiply,&f);

    printf("Printing the tree.\n");
    PrintTree(tree);

    printf("Searching for %d\n", d);
    printf("Should find %d, found %d\n",d,*(int*)BstFind(tree,&d));
    
    printf("Destroying BST\n");
    BstDestroy(tree);

    if(NULL == tree)
    {
        printf("Tree was destroyed :(\n");
    }
    else
    {
        printf("Tree lives forever.\n");
    }
    
    return 0;
}

