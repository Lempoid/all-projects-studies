#ifndef __HASH_H__
#define __HASH_H__

#include <stddef.h> /* for size_t */

typedef struct hash_table hash_t;
typedef int   (*action_func_hash_t)(void *data, void *param);
typedef int   (*match_func_hash_t)(const void *data, void *param);
typedef size_t   (*hash_function_t)(void* key);

/* Creates a hash table and returns it.
   Returns NULL upon failure. */   
hash_t *HashCreate(const size_t size, hash_function_t function, 
                  match_func_hash_t compare);

/* Destroys the hash table.
   Call when done working with the table. 
   Time Complexity: O(n) 
   Note: It is legal to destroy NULL.*/
void HashDestroy(hash_t* table);

/* Removes the list referred to by index.
   Returns true upon success and false upon failure.
   O(n) */
int HashRemove(const void* key, hash_t* table);

/* Inserts data as a new node, to before the element referred to by cur.
   Returns an iterator to the new element, or list end upon failure. 
   Time Complexity: O(1) */
int HashInsert(const void* key, hash_t* table, const void* data);

/* Returns the total number of elements in the list. 
   Time Complexity: O(n) */
size_t HashSize(const hash_t* table);

/* Returns 1 if the list is empty, 0 if it's not.
   Time Complexity: O(n) */
int HashIsEmpty(const hash_t* table);

/* In the range of the list, find and return the first element 
   whose data matches the key when compared using the is_match_func function.
   The is_match_func function should return 1 if the data matches.
   Returns the first element that matches, or false if not found.
   O(n) */                                       
void* HashFind(const hash_t* table, match_func_hash_t is_match_func, 
               hash_function_t function, const void *key);

/* Sends the data from each element in the hash table (in order) to the 
   function action_func, along with param. Stops if action_func 
   fails (return != 0), even if not all elements have been sent.
   Returns the value returned from the last call to action_func.
   Time Complexity: O(n) */                                
int HashForEach(const hash_t* table, action_func_hash_t action_func, 
               const void *param);


#endif 		/* __HASH_H__ */