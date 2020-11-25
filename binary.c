#include<stdio.h>

void binary(int);

int main()
{
	int n;

	printf("Introduce un numero:\n");
	scanf("%d", &n);

	binary(n);
	return 0;
}

void binary(int n)
{
	for (int i = 0; i < 8 * sizeof(int); i++)
	{
		if (n % 2 == 0)
			printf("0");
		else
			printf("1");

		n >>= 1;
	}
}
