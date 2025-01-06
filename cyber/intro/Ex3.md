This is a buffer overflow vulnerability which is caused by contiguously writing to memory beyond the reserved range given by the system (we reserved 8 chars `username[8]` and wrote 9) and thus overwriting the next memory segment which in our case was the `allow` variable.

***Note:***
Linux has a built in stack smashing protection. We should compile the file with the protection off `gcc -g -fno-stack-protector fileName.c`

First fix would be changing the `gets()` function into `fgets()` which does check if the input exceeded the reserved space.
Second fix would be to hard code the check and turn it into `if(1 == allow)` and so mitigate the chance of the exploit.

Mitigate, because code injection is still possible with buffer over flow.

