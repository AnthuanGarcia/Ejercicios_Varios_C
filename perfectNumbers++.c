#include<stdio.h>

typedef unsigned long long int bint;

int perfect(int);
bint power(int, int);

int main()
{
	perfect(6);
	return 0;
}

bint power(int a, int n)
{
	int res = 1;

	if (n % 2 == 0)
	{
		for (int i = 0; i < n / 2; i++)
			res *= a;

		return res * res;
	}

	for (int i = 0; i < n; i++)
		res *= a;

	return res;
}

int perfect(int a)
{
	int prime = 2;
	int isPrime = 1;
	int count = 0;
	bint nperfect = 0;

	while (1)
	{
		for (int i = 2; i <= prime / 2; i++)
			if (prime % i == 0)
			{
				isPrime = 0;
				break;
			}
		
		if (isPrime)
		{
			nperfect = power(2, prime - 1) * (power(2, prime) - 1);
			printf("%4d: %10llu\n", ++count, nperfect);
			
			if (count == a) return 0;
		}

		prime++;
		isPrime = 1;
	}
}
