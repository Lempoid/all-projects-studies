/*
Alex Breger
Reviewed: Hananya Tampleman somewhere between 22-28.9.24
*/

#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef struct slist slist_t;
typedef struct slist_node *slist_iter_t;

typedef int (*action_func_t)(void *data, void *param);
typedef int (*match_func_t)(const void *data, void *param);

/* Creates an empty list and returns it.
   Returns NULL upon failure.
   Call SListDestroy when done working with the list. */
slist_t *SListCreate(void);

/* Destroys the list.
   Call when done working with the list. 
   Time Complexity: O(n) 
   Note: It is legal to destroy NULL.*/
void SListDestroy(slist_t *list);

/* Returns an iterator to the first element.
   If the list is empty returns SListEnd.
   Time Complexity: O(1) */
slist_iter_t SListBegin(const slist_t *list);

/* Returns an iterator to beyond the last element (out of range).
   Time Complexity: O(1) */
slist_iter_t SListEnd(const slist_t *list);

/* Returns an iterator to the element following cur.
   Do not use or go beyond SListEnd().    
   Time Complexity: O(1) */
slist_iter_t SListNext(slist_iter_t iter);

/* Returns true if both iterators refer to the same element. */
int SListIterIsEqual(slist_iter_t one, slist_iter_t other);

/* Returns the data from the element referred to by iter. */
void *SListGetData(slist_iter_t iter);

/* Sets the data in the node refered to by iter. */
void SListSetData(slist_iter_t iter, void *data);

/* Inserts data as a new element, to before the element referred to by cur.
   Returns an iterator to the new element, or SListEnd(list) upon failure. 
   Time Complexity: O(1) */
slist_iter_t SListInsert(slist_t *list,slist_iter_t where, void *data);

/* Removes the node referred to by cur.
   Returns an iterator to the element following cur.
   O(1) */
slist_iter_t SListRemove(slist_iter_t iter);

/* Returns 1 if the list is empty, 0 if it's not.
   Time Complexity: O(1) */
int SListIsEmpty(const slist_t *list);

/* Returns the number of elements in the list. 
   Time Complexity: O(n) */
size_t SListCount(const slist_t *list);

/* In the range between begin and end, find and return the first element 
   whose data matches param when compared using the is_match_func function.
   The is_match_func function should return 1 if the data matches.
   Returns the first element that matches, or to if not found.
   O(n) */
slist_iter_t SListFind(slist_iter_t from,
                        slist_iter_t to,
                        match_func_t is_match_func,
                        void *param);

/* Sends the data from each element in the list (in order) to the 
   function action_func, along with param. Stops if action_func 
   fails (return != 0), even if not all elements have been sent.
   Returns the value returned from the last call to action_func.
   Time Complexity: O(n) */
int SListForEach(slist_iter_t from,
                 slist_iter_t to,
                 action_func_t action_func, void *param);

#endif /*__SLIST_H__*/