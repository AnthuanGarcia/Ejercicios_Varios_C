#include<stdio.h>

int isprime(int);
int attractive(int);

int main(void)
{
	int num = 120;

	printf("Numeros atractivos hasta el %d:\n", num);
	for (int i = 1; i <= num; i++)	
		if (attractive(i))
			printf("%3d, ", i);

	return 0;
}

int isprime(int n)
{
	int isPrime = 1;

	if (n == 2) return isPrime;

	for (int i = 2; i <= n / 2; i += 2)
		if (n % i == 0)
		{
			isPrime = 0;
			break;
		}

	return isPrime;
}

int attractive(int n)
{
	int factors = 0;
	int divider = 2;

	if (n == 1) return 0;

	while (n > 1)
	{
		if (isprime(divider))

			if (n % divider == 0)
			{
				n /= divider;
				factors++;
			}
			else
				divider > 2 ? divider += 2 : divider++;

		else
			divider > 2 ? divider += 2 : divider++;
	}

	if (factors == 1)
		return 0;

	return isprime(factors);
}
