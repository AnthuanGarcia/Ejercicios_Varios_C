#include<stdio.h>

int primes(int);

int main()
{
	printf("%d\n", primes(10000));
	return 0;
}

int primes(int a)
{
	int prime = 1;
	int isPrime = 1;
	int count = 0;

	while (1)
	{
		if (prime - 1 == 2) printf("%4d: %5d\n", ++count, 2);

		for (int i = 3; i <= prime / 2; i += 2)
			if (prime % i == 0)
			{
				isPrime = 0;
				break;
			}
		
		if (isPrime)
		{
			printf("%4d: %5d\n", ++count, prime);

			if (count == a) return prime;
		}

		prime += 2;
		isPrime = 1;
	}
}
