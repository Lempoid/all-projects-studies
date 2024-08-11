#ifndef __COUNTENVVARS_H__
#define __COUNTENVVARS_H__
#include <stddef.h> /*size_t*/

size_t count_env_vars();
char** to_lower_env(char** env_vars, size_t size);

#endif /*__COUNTENVVARS_H__*/
