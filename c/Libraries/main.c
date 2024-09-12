#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    void (*Foo)(int);
    char *error;

    handle = dlopen("./libfoo.so", RTLD_LAZY);
    if (!handle) 
    {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    Foo = (void (*)(int))dlsym(handle, "Foo");
    if ((error = dlerror()) != NULL) 
    {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return 1;
    }

    (*Foo)(31);

    dlclose(handle);
    return 0;
}