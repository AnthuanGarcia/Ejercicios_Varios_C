#include<stdio.h>

typedef unsigned long long bigInt;

int gapful(bigInt);
void printResults(bigInt, int);

int main()
{
	printResults(100, 30);
	printf("\n");
	printResults(1000000, 15);
	printf("\n");
	printResults(1000000000, 15);
	printf("\n");

	return 0;
}

int gapful(bigInt n)
{
	bigInt m = n;

	while (m >= 10)
		m /= 10;

	return (n % (m * 10 + (n % 10)) == 0) ? 1 : 0;
}

void printResults(bigInt start, int n)
{
	int count = 0;

	printf("Primeros %d numeros con huecos, mayores a %llu:\n", n, start);

	for (bigInt i = start; count < n; i++)
		if (gapful(i))
			printf("%3d: %llu\n", ++count, i);
}
