#include <stdio.h>

int happyNumber(int);
int* splitNumber(int, int);

int main()
{
	for (int i = 1, count = 0; i < 1000; i++)
		if (happyNumber(i))
			printf("%d: %d\n", ++count, i);

	return 0;
		
}

int power(int a, int n)
{
	int res = 1;

	for (int i = 0; i < n; i++)
		res *= a;

	return res;
}

int* splitNumber(int a, int parts)
{
	static int splitedNum[15];
	int spl = power(10, parts);
	int i = 0;

	while (a != 0)
	{
		splitedNum[i++] = a % spl;
		a /= 10;
	}

	splitedNum[i] = EOF;

	return splitedNum;
}

int happyNumber(int n)
{
	int sum = 0, iterations = 0;

	do {
		if (n == 1) return 1;

		int* happy = splitNumber(n, 1);
		
		for (int i = 0; happy[i] != EOF; i++)
			sum += happy[i] * happy[i];

		n = sum;
		sum = 0;
		iterations++;

	} while(sum != 1 && iterations <= 10);

	return 0;
}
