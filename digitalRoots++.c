#include<stdio.h>

int digitalRoot(int);

int main()
{
	for (int i = 0; i <= 100; i++)
	{
		if (i % 9 == 0)
		{
			printf("%d\n", digitalRoot(i));
			continue;
		}
		printf("%d, ", digitalRoot(i));
	}

	return 0;
}

int digitalRoot(int a)
{
	return (a % 9 != 0) ? a % 9 : 9;
}
