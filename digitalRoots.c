#include<stdio.h>

int* splitNumber(int, int);
int digitalRoot(int);

int main()
{
	for (int i = 0; i <= 100; i++)
	{
		if (i % 9 == 0)
		{
			printf("%1d\n", digitalRoot(i));
			continue;
		}

		printf("%1d, ", digitalRoot(i));
	}

	return 0;
}

int power(int a, int n)
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

int* splitNumber(int n, int parts)
{
	static int splitedNumber[50];
	int spl = power(10, parts);
	int i = 0;

	while (n != 0)
	{
		splitedNumber[i++] = n % spl;
		n /= 10;
	}

	splitedNumber[i] = EOF;

	return splitedNumber;
}

int digitalRoot(int n)
{
	int sum = 0;
	int *splitN;

	while (1)
	{
		splitN = splitNumber(n, 1);

		for (int i = 0; splitN[i] != EOF; i++)
			sum += splitN[i];

		n = sum;
		
		if (sum <= 9) return sum;

		sum = 0;
	}
}
