To exploit the vulnerability, simply write beyond the buffer capacity, in our case it will be 9 characters. If I type 11111111, the last character will be written to `allow` and will be equal (hex) 0x31 which is not 0x0.

![[Pasted image 20250106154901.png]]

And here we see that allow equals 0x31, which is the hex for ASCII '1'.
![[Pasted image 20250106154959.png]]

And because if allow is not 0, it will go through to `PrivilegedAction()`