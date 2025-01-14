1) I went to gdb and went through instructions starting at main until I found the output for password. 
   Then I looked for any comparison and saw a call to `memcmp` after a few more instructions between a memory location and a register. I have printed the strings in the memory location `x/10s $rip + 0x9eb94` and it printed some strings which I tried out and found `super_long_and_complicated_password` to be the password.
2) I can use strings and try to search for a hardcoded password check as well.
3) We can brute force passwords but it is not interesting.