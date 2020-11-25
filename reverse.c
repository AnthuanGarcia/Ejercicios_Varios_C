#include<stdio.h>

int reverse(int);

int main()
{
	int n;
	printf("Escribe un numero:\n");
	scanf("%d", &n);

	n = reverse(n);

	printf("Numero volteado: %d\n", n);
	return 0;
}

int reverse(int n)
{
	int rem = 0, part = 0;

	while (n != 0)
	{
		part = n % 10;
		rem = (rem * 10) + part;
		n /= 10;
	}

	return rem;
}
