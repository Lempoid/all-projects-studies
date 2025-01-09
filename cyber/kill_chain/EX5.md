```
sources: https://tinyurl.com/3uv2y2n6, https://tinyurl.com/45rdcts8
```

| Type        | 32 bit   | 64 bit   |
| ----------- | -------- | -------- |
| char        | 1 byte   | 1 byte   |
| short       | 2 bytes  | 2 bytes  |
| int         | 4 bytes  | 4 bytes  |
| long        | 4 bytes  | 8 bytes  |
| long long   | 8 bytes  | 8 bytes  |
| float       | 4 bytes  | 4 bytes  |
| double      | 8 bytes  | 8 bytes  |
| long double | 16 bytes | 16 bytes |
***Preview:***

We reach the `func` function. And I start my answer from there.

```c
#include <stdio.h>

void func(long a, long b) {

  // Insert lines here
  long* return_addr = (long*)__builtin_frame_address(0) + 1;
  *return_addr += 6;
  return;
  printf("%ld\n", b);
  printf("%ld\n", a);
}

int main() {
  int num = 3;
  func(3, 1);
  num = 4;
  printf("num is now %d\n", num);

  return 0;
}

```

`  long* return_addr = (long*)__builtin_frame_address(0) + 1;` 
This gives us the return address of the current frame, +1 gives us the returning address to main.

`  *return_addr += 6;` 
We add to the return address 6 bytes so we are able to skip the `num = 4` instruction. We want to return to the addresses as marked here:

![[Pasted image 20250109110816.png]]
