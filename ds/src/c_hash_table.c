/*
Alex Breger
Reviewed: Chananya Templeman 6.10.24
*/

#include <stdlib.h> /*free calloc*/
#include <stdio.h> /*fprintf*/
#include "c_hash_table.h"
#include "slist.h"

struct hash_table
{
    slist_t **array;
    size_t size;
    hash_function_t hash_function;
    match_func_hash_t match_function;
};

hash_t *HashCreate(const size_t size, hash_function_t hash_function, 
match_func_hash_t match_function)
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

int HashRemove(const void* key, hash_t* table)
{
    size_t index = table->hash_function((void*)key) % table->size;
    slist_t* list = table->array[index];
    slist_iter_t start = SListBegin(list);
    slist_iter_t end = SListEnd(list);

    if (index >= table->size || table->array[index] == NULL)
    {
        return 0;
    }

    while (!SListIterIsEqual(start, end)) 
    {
        if (0 == table->match_function(key, SListGetData(start))) 
        {
            SListRemove(start);

            return 1;
        }

        start = SListNext(start);
    }


    return 1;
}

int HashInsert(const void* key, hash_t* table, const void* data)
{
    size_t index = table->hash_function(key) % table->size;
    SListInsert(table->array[index], SListBegin(table->array[index]), data);

    return 1;
}

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

void* HashFind(const hash_t* table, match_func_hash_t is_match_func, 
hash_function_t hash_function, const void *key)
{
    size_t index = table->hash_function(key) % table->size;
    slist_iter_t result;
    
    result = SListFind(SListBegin(table->array[index]), SListEnd(table->array[index]), is_match_func, key);

    if(NULL == result)
    {
        return NULL;
    }

    return SListGetData(result);
}

                            
int HashForEach(const hash_t* table, action_func_hash_t action_func, 
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