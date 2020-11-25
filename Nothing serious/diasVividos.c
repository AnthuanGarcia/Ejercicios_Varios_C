#include <stdio.h>

int daysAlive(int);

int main()
{
	int years;
	printf("Introduce la cantidad de años:\n");
	scanf("%d", &years);

	printf("Los dias vividos son: %d\n", daysAlive(years));
	
	return 0;
}

int daysAlive(int years)
{
	int days = 0;

	for (int i = 2020 - years; i < 2020; i++)
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			days += 364;
		else
			days += 365;

	return days;
}
