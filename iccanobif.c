#include<stdio.h>

typedef unsigned long long int bint; 

bint reverse(bint);
void iccanobif(int);

int main()
{
	iccanobif(100);
	return 0;
}

bint reverse(bint a)
{
	bint rem = 0, spl = 0;

	while (a != 0)
	{
		spl = a % 10;
		rem = rem * 10 + spl;
		a /= 10;
	}

	return rem;
}

void iccanobif(int n)
{
	int count = 0;
	bint a = 0;
	bint b = 1;
	bint c = 0;

	while (count != n)
	{
		printf("%3d: %20llu\n", ++count, c);
		c = reverse(c);

		a = b;
		b = c;
		c = a + b;
	}
}
