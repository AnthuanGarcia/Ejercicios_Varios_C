#include <stdio.h>

int sumFib(int, int, int, int);

int main()
{
	printf("La suma de los terminos entre 100 y 10.000 de la serie de Fibonacci es: %d", sumFib(0, 1, 0, 0));

	return 0;
}

int sumFib(int a, int b, int c, int sum)
{	
	if (c >= 100)
		sum += c;

	if (c >= 10000)
		return sum;

	a = b;
	b = c;

	return sumFib(a, b, a + b, sum);
}
