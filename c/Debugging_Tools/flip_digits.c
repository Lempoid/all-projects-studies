#include <stdio.h>

int FlipDigits(int n);

int main()
{

int x=12340;

x = FlipDigits(x);
printf("%d", x);

return 0;
}


int FlipDigits(int n)
{
	int tmp = 0;
	while(n > 9)
	{
		
		tmp += n%10;
		tmp *= 10;
		n/=10;
		
	}
	tmp += n;	

	return tmp;
}
