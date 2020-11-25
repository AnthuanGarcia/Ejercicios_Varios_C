#include <stdio.h>

//int* splitNumber(int, int);
//int power(int, int);
int kaprekarN(int, int);

int main()
{
	for (int i = 1; i <= 10000; i++)
		if (kaprekarN(i, 10))
			printf("%ld\n", i);

	return 0;
}

int kaprekarN(int n, int base)
{
	int N = n * n;
	int r;
	int tens = 1;

	if ((N - n) % (base - 1))
		return 0;

	while (tens < n) tens *= base;

	if (n == tens)
		return 1 == n;

	while ((r = N % tens) < n)
	{
		if (N / tens + r == n)
			return tens;
		tens *= base;
	}

	return 0;
}
