#include <stdlib.h> /*free calloc*/
#include <stdio.h> /*fprintf*/
#include "c_hash_table.h"
#include "slist.h"

struct hash_table
{
    slist_t **array;
    size_t size;
    hash_function_t hash_function;
    match_func_t match_function;
};

/* Creates a hash table and returns it.
   Returns NULL upon failure. */   
hash_t *HashCreate(const size_t size, hash_function_t hash_function, 
match_func_t match_function)
{
    size_t i;
    hash_t* hash_table = calloc(1,sizeof(hash_t));
    if (NULL == hash_table)
    {
        fprintf(stderr,"Can't allocate memry for hash table. Returning NULL.\n");
        return NULL;
    }
    
    hash_table->array = calloc(size, sizeof(slist_t*));
    if (NULL == hash_table->array)
    {
        fprintf(stderr,"Can't allocate memory for hash table. Returning NULL.\n");
        return NULL;
    }

    hash_table->size = size;
    hash_table->hash_function = hash_function;
    hash_table->match_function = match_function;

    for (i = 0; i < size; i++)
    {
        hash_table->array[i] = SListCreate();
    }
    

    return hash_table;
}

/* Destroys the hash table.
   Call when done working with the table. 
   Time Complexity: O(n) 
   Note: It is legal to destroy NULL.*/
void HashDestroy(hash_t* table)
{
    size_t i;
    for(i = 0; i < table->size; ++i)
    {
        SListDestroy(table->array[i]); 
    }

    free(table->array);
    free(table);
}

/* Removes the list referred to by index.
   Returns true upon success and false upon failure.
   O(n) */
int HashRemove(const void* key, hash_t* table)
{
    size_t index = table->hash_function(key);
    
    if (index >= table->size || table->array[index] == NULL)
    {
        return 0;
    }

    SListRemove(table->array[index]);
    table->array[index] == NULL;

    return 1;
}

/* Inserts data as a new node, to before the element referred to by cur.
   Returns an iterator to the new element, or list end upon failure. 
   Time Complexity: O(1) */
int HashInsert(const void* key, hash_t* table, const void* data)
{
    size_t index = table->hash_function(key);
    SListInsert(table->array[index], 0, data);

    return 1;
}

/* Returns the total number of elements in the list. 
   Time Complexity: O(n) */
size_t HashSize(const hash_t* table)
{
    size_t count = 0;
    size_t i;
    
    for(i = 0; i < table->size; ++i)
    {
        count += SListCount(table->array[i]);
    }

    return count;
}

/* Returns 1 if the list is empty, 0 if it's not.
   Time Complexity: O(n) */
int HashIsEmpty(const hash_t* table)
{
    size_t i;

    for(i = 0; i < table->size; ++i)
    {
        if(0 == SListIsEmpty(table->array[i]))
        {
            return 0;
        }
        
    }

    return 1;
}

/* In the range of the list, find and return the first element 
   whose data matches the key when compared using the is_match_func function.
   The is_match_func function should return 1 if the data matches.
   Returns the first element that matches, or false if not found.
   O(n) */                                       
void* HashFind(const hash_t* table, match_func_t is_match_func, 
hash_function_t hash_function, const void *key)
{
    void* data_from_hash_table;
    slist_iter_t result;
    
    result = SListFind(SListBegin(hash_function(key)),SListEnd(hash_function(key)),is_match_func, key);

    if(NULL == result)
    {
        return 0;
    }

    return 1;
}

/* Sends the data from each element in the hash table (in order) to the 
   function action_func, along with param. Stops if action_func 
   fails (return != 0), even if not all elements have been sent.
   Returns the value returned from the last call to action_func.
   Time Complexity: O(n) */                                
int HashForEach(const hash_t* table, action_func_t action_func, 
const void *param)
{
    size_t i;
    int result;

    for (i = 0; i < table->size; ++i)
    {
        result = SListForEach(SListBegin(table->array[i]),SListEnd(table->array[i]),action_func,param);
        if(0 == result)
        {
            return result;
        }
    }
    
    return result;
}