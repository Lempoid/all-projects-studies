#include <stdio.h>

void func2(void *arg)
{
    long f2;
    printf("Enter func2\n");
    /* AREA2 */
    printf("Exit func2\n");
    void **ret = (void**)&f2 + 2;
    *ret = (void*)0x00005555555551e7;
}

void func1()
{
    long f1;
    printf("Enter func1\n");
    func2(&f1);
    printf("Exit func1\n");
}

int main()
{
    const long x=1;
    long y=5;

    printf("x=%lu\n",x);

    func1();

    printf("Exit main\n");
    return 0;
}