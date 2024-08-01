#include <stdio.h>

int power(int n);

int main()
{

int x = 5;
x = power(x);
printf("%d", x);
return 0;
}



int power(int n)
{ 
	int x = 1;
        for (int i = 0; i < n; i++)
        {
              x = x * 10;
        }

	return x;
}




