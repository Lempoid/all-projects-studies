
Code 1:
We check if some data in a memory location is equal to 1 -> If it is greater, we jump to L2 label -> if greater, we ask for an argument, mov 1 to aex and jump to L3.

L2 -> 



1) Syntax is intel. Much more readable.
2) It is a size directive. That's how the assembler infer the size of a given data in the memory address. there BYTE PTR and WORD PTR and DWORD PTR. 1, 2 and 4 bytes. It does an AND operation with 1's the size of specified PTR.
3) `mov rdi, QWORD PTR [rsi + 8]` mov into rdi register a QWORD size data from memory at rsi + 8 bytes.
4) doing xor of a value with itself will give us 0. In our case, `xor eax, eax` will zero the register.