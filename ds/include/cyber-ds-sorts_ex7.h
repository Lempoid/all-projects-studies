#ifndef __CYBER_DS_SORTS_EX7_H__
#define __CYBER_DS_SORTS_EX7_H__

#include <stddef.h>

void RecursiveQsort(void *base, size_t nmemb, size_t size,
                  int (*compar)(const void *, const void *));

#endif /*__CYBER_DS_SORTS_EX7_H__*/