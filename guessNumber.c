#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randomint(int, int);
void guess(int);

int main()
{
	guess(randomint(1, 10));

	/*for (int i = 0; i < 5; i++)
	{
		_sleep(1000);
		printf("%d\n", randomint(1, 10));
	}*/

	return 0;
}

int randomint(int min, int max)
{
	int res, low, hi;

	res = low = hi = 0;

	if (min < max)
	{
		low = min;
		hi = max + 1;
	}
	else
	{
		low = max + 1;
		hi = min;
	}

	srand(time(NULL));
	res = (rand() % (hi - low)) + low;
	return res;
}

void guess(int n)
{
	int a = 0;
	while (a != n)
	{
		printf("Introduce un numero entre 1 y 10:\n");
		scanf("%d", &a);

		if (a < n)
			printf("Numero Incorrecto, el numero es mayor\n");

		if (a > n)
			printf("Numero Incorrecto, el numero es menor\n");

		printf("\n");
	}

	printf("�Haz adivinado el numero, bien hecho!\n");
}
