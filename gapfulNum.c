#include <stdio.h>

typedef unsigned long long ultraint;

int gapful(ultraint);
void printResults(ultraint, int);

int main()
{
	printResults(100, 30);
	printf("\n");
	printResults(1000000, 15);
	printf("\n");
	printResults(1000000000, 15);

	return 0;
}

int power(int a, int n)
{
	int res = 1;

	for (int i = 0; i < n; i++)
		res *= a;

	return res;
}

int* splitedNumber(ultraint n, int parts)
{
	static int splitNum[50];
	int spl = power(10, parts);
	int i = 0;

	while (n != 0)
	{
		splitNum[i++] = n % spl;
		n /= spl;
	}

	splitNum[i] = EOF;

	return splitNum;
}

int gapful(ultraint n)
{
	int i;
	int* splitn = splitedNumber(n, 1);
	for (i = 0; splitn[i] != EOF; i++);
	int nogaps = splitn[i - 1] * 10 + splitn[0];

	return (n % nogaps == 0) ? 1 : 0;
}

void printResults(ultraint start, int n)
{
	int count = 0;

	printf("Primeros %d numeros con huecos mayores a %llu:\n", n, start);

	for (ultraint i = start; count < n; i++)
		if (gapful(i))
			printf("%3d: %llu\n", ++count, i);
}
