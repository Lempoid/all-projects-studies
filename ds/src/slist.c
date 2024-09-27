#include <stdio.h>	/*fprintf*/
#include <stdlib.h> /*free calloc*/
#include "slist.h"

struct slist
{
	slist_iter_t start_node;
	slist_iter_t end_node;
};

struct slist_node
{
	void *data;
	slist_iter_t next;
};

/* Creates an empty list and returns it.
   Returns NULL upon failure.
   Call SListDestroy when done working with the list. */
slist_t *SListCreate(void)
{
	slist_t *list_manager = calloc(1, sizeof(slist_t));
	slist_iter_t start_dummy = calloc(1, sizeof(slist_iter_t));
	slist_iter_t end_dummy = calloc(1, sizeof(slist_iter_t));

	if (NULL == start_dummy || NULL == end_dummy || NULL == list_manager)
	{
		fprintf(stderr, "Failed to create list. Returning NULL.\n");
		free(start_dummy);
		free(end_dummy);
		free(list_manager);
		return NULL;
	}

	start_dummy->data = NULL;
	end_dummy->data = NULL;
	start_dummy->next = end_dummy;
	end_dummy->next = NULL;

	list_manager->end_node = end_dummy;
	list_manager->start_node = start_dummy;

	return list_manager;
}

/* Destroys the list.
   Call when done working with the list.
   Time Complexity: O(n)
   Note: It is legal to destroy NULL.*/
void SListDestroy(slist_t *list)
{
	slist_iter_t node_to_destroy = list->start_node->next;
	slist_iter_t runner;

	while (node_to_destroy != list->end_node)
	{
		runner = node_to_destroy->next;
		free(node_to_destroy);
		node_to_destroy = runner;
	}

	free(list->end_node);
	list->end_node = NULL;
	free(list->start_node);
	list->start_node = NULL;
	free(list);
	list = NULL;
}

/* Returns an iterator to the first element.
   If the list is empty returns SListEnd.
   Time Complexity: O(1) */
slist_iter_t SListBegin(const slist_t *list)
{
	if (list->end_node == list->start_node->next)
	{
		return list->end_node;
	}
	else
	{
		return list->start_node->next;
	}
}

/* Returns an iterator to beyond the last element (out of range).
   Time Complexity: O(1) */
slist_iter_t SListEnd(const slist_t *list)
{
	return list->end_node;
}

/* Returns an iterator to the element following cur.
   Do not use or go beyond SListEnd().
   Time Complexity: O(1) */
slist_iter_t SListNext(slist_iter_t iter)
{
	if (NULL == iter)
	{
		fprintf(stderr, "Iterator is null, returning NULL.\n");
		return NULL;
	}

	return iter->next;
}

/* Returns true if both iterators refer to the same element. */
int SListIterIsEqual(slist_iter_t one, slist_iter_t other)
{
	return one == other;
}

/* Returns the data from the element referred to by iter. */
void *SListGetData(slist_iter_t iter)
{
	if (NULL == iter)
	{
		fprintf(stderr, "Element is NULL. Returning NULL.");
		return NULL;
	}
	return iter->data;
}

/* Sets the data in the node refered to by iter. */
void SListSetData(slist_iter_t iter, void *data)
{
	if (NULL == iter)
	{
		fprintf(stderr, "Element is NULL.No data to return.");
		return;
	}

	iter->data = data;
}

/* Inserts data as a new element, to before the element referred to by cur.
   Returns an iterator to the new element, or SListEnd(list) upon failure.
   Time Complexity: O(1) */
slist_iter_t SListInsert(slist_t *list, slist_iter_t where, void *data)
{

	slist_iter_t node_to_insert = calloc(1, sizeof(slist_iter_t));

	if (NULL == list)
	{
		fprintf(stderr, "List is null, returning NULL.\n");
		return NULL;
	}

	if (NULL == node_to_insert)
	{
		fprintf(stderr, "Failed to create new node, returning last element.\n");
		return list->end_node;
	}

    node_to_insert->data = where->data;
    node_to_insert->next = where->next;

	where->data = data;
    where->next = node_to_insert;

    if(node_to_insert->next == list->end_node)
    {
        list->end_node->next = where;
    }

    return where;
}

/* Removes the node referred to by cur.
   Returns an iterator to the element following cur.
   O(1) */
slist_iter_t SListRemove(slist_iter_t iter)
{
	slist_iter_t node_to_remove;

	if (iter->next->next == iter)
	{
		fprintf(stderr, "Can't remove the last node. Returning iterator to end.\n");
		return iter->next;
	}
	
	node_to_remove = iter->next;

	if(NULL == iter->data)
	{
		iter->next = iter->next->next;
		free(node_to_remove);
		return iter->next;
	}

    iter->data = node_to_remove->data;

    iter->next = node_to_remove->next;

    if(iter->next->next == iter)
    {
        iter->next->next = iter->next;
    }

    free(node_to_remove);

    return iter;
}

/* Returns 1 if the list is empty, 0 if it's not.
   Time Complexity: O(1) */
int SListIsEmpty(const slist_t *list)
{
	if (NULL == list)
	{
		fprintf(stderr, "List is null. Returning -1.");
		return -1;
	}

	if (list->end_node == list->start_node->next)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* Returns the number of elements in the list.
   Time Complexity: O(n) */
size_t SListCount(const slist_t *list)
{
	size_t count;
	slist_iter_t runner;

	if (NULL == list)
	{
		fprintf(stderr, "List is null. Returning 0.");
		return 0;
	}

	count = 0;
	runner = list->start_node->next;

	while (runner != list->end_node)
	{
		++count;
		runner = runner->next;
	}

	return count;
}

/* In the range between begin and end, find and return the first element
   whose data matches param when compared using the is_match_func function.
   The is_match_func function should return 1 if the data matches.
   Returns the first element that matches, or to if not found.
   O(n) */
slist_iter_t SListFind(slist_iter_t from, slist_iter_t to, match_func_t is_match_func, void *param)
{
	if (NULL == from || NULL == to)
	{
		fprintf(stderr, "One of the iterators is NULL, returning the second sent iterator.");
		return to;
	}

	while (from != to)
	{
		if (1 == is_match_func(from->data, param))
		{
			return from;
		}
		from = from->next;
	}

	return to;
}

/* Sends the data from each element in the list (in order) to the
   function action_func, along with param. Stops if action_func
   fails (return != 0), even if not all elements have been sent.
   Returns the value returned from the last call to action_func.
   Time Complexity: O(n) */
int SListForEach(slist_iter_t from, slist_iter_t to, action_func_t action_func, void *param)
{
	int result = 0;

	if (NULL == from || NULL == to)
	{
		fprintf(stderr, "One of the iterators is NULL, returning 0.");
		return 0;
	}

	while (from != to)
	{
		if (0 == action_func(from->data, param))
		{
			result = action_func(from->data, param);
			break;
		}
		from = from->next;
	}

	return result;
}
