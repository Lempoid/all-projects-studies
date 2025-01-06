```c
#include <stdio.h>
#include <string.h>

int IsAllowedUser(char *a)
{
	return 0;
}

void PrivilegedAction()
{
    printf("imprint");
}

int main()
{
    char username[8];
	 int allow = 0;

    printf("Enter your username, please: ");
    gets(username);
    if (IsAllowedUser(username))
    {
        allow = 1;
    }
    if (allow)
    {
        PrivilegedAction();
    }
    return 0;
}
```

I have added a declaration and definition of `IsAllowrdUser(char* a)` which will always return 0 so it won't ever turn `allow` to 1 in a conventional way.

The problem with the code below is that the function `gets()` doesn't check input length 
and so it may go beyond the buffer and set the `allow` variable to anything (which most likely won't be 0) and thus `if (allow)` which fails only if `allow == 0` will evaluate to true.

From `gets()` man page:

	DESCRIPTION 
       _Never use this function_.

       gets() reads a line from _stdin_ into the buffer pointed to by _s_
       until either a terminating newline or **EOF**, which it replaces with
       a null byte ('\0').  No check for buffer overrun is performed
       
       ## BUGS         
       Never use **gets**().  Because it is impossible to tell without
       knowing the data in advance how many characters **gets**() will read,
       and because **gets**() will continue to store characters past the end
       of the buffer, it is extremely dangerous to use.  It has been
       used to break computer security.  Use **fgets**() instead.

       For more information, see CWE-242 (aka "Use of Inherently
       Dangerous Function") at
       [http://cwe.mitre.org/data/definitions/242.html](http://cwe.mitre.org/data/definitions/242.html)
   

