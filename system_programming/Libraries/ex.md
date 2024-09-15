1) For static linking I have created the foo.c and main.c files.
The foo.c file was compiled into and object file and turned into archive and compiled as a static library and then compiled (linked) with main.c and the archive in static way to get a binary.

gcc -c foo.c -o foo.o # Object file compilation
ar rcs libfoo.a foo.o # Archive creation
gcc main.c -L. -lfoo -o static_program # Compile with static library.


2) This time foo.c was turned into a shared object with PIC attribute, then compiled into a binary. Then the path to search for the dynamic library was updated.

gcc -fPIC -shared foo.c -o libfoo.so # shared object with PIC
gcc main.c -L. -lfoo -o dynamic_program
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/git/c/Libraries/


3) Same as 2. But compiled with -ldl to get the LD API. 
The main was changed to load explicitly the library using LD API.

gcc main.c -ldl -o explicit_dynamic_program
