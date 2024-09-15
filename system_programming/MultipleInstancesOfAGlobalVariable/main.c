#include <stdio.h>
#include <dlfcn.h>
#include "global.h"

int main()
{

	void(*foo)();
	void(*foo2)();
	void *fooHandle = dlopen("./libdynamic1.so", RTLD_LAZY | RTLD_GLOBAL);
	void *foo2Handle = dlopen("./libdynamic2.so", RTLD_LAZY);

	if(fooHandle && foo2Handle)
	{
		*(void**)&foo = dlsym(fooHandle, "Foo");
		*(void**)&foo2 = dlsym(foo2Handle,"Foo2");
	}

	if(foo && foo2)
	{
		printf("Dyn1 ");
		foo();
		printf("Dyn2 ");
		foo2();
	}

	dlclose(fooHandle);
	dlclose(foo2Handle);

	return 0;
}