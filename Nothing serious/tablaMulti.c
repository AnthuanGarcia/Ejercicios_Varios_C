#include <stdio.h>

void displayTable(int n);

int main()
{
	int n;

	printf("Introduce la tabla de multiplicar que deseas:\n");
	scanf("%d", &n);

	printf("\n");
	displayTable(n);

	return 0;
}

void displayTable(int n)
{
	for (int i = 1; i <= 10; i++)
		printf("%d * %d = %d\n", n, i, n * i);
}
