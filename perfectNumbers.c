#include<stdio.h>

//typedef unsigned long long int bint;

int perfectN(int);

int main()
{
	int count = 0;

	for (int i = 1; i <= 10000; i++)
		if (perfectN(i) == i)
			printf("%2d: %4d\n", ++count, perfectN(i));
	return 0;
}

int perfectN(int a)
{
	int sum = 0;

	for (int i = 1; i < a; i++)
		if (a % i == 0)
			sum += i;

	return sum;
}
