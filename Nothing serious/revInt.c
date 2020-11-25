#include<stdio.h>

int reverseInteger(int, int, int);

int main()
{
	int n;
	printf("Introduce un numero:\n");
	scanf("%d", &n);

	printf("Numero volteado:\n%d", reverseInteger(n, 0, 0));
	return 0;
}

int reverseInteger(int n, int rem, int part)
{
	if (part == 0 && n == 0)
		return rem;

	return reverseInteger(n / 10, rem * 10 + part, n % 10);
}
