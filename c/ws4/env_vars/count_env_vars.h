#ifndef __COUNTENVVARS_H__
#define __COUNTENVVARS_H__
#include <stddef.h> /*size_t*/

size_t CountEnvVars(char** env_vars);
char** ToLowerEnv(char** env_vars, size_t size);
void PrintEnv(char** arrayToPrint, size_t size);

#endif /*__COUNTENVVARS_H__*/
