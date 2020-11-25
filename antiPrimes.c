#include<stdio.h>

void antiprimes(int);

int main()
{
	antiprimes(30);
	return 0;
}

void antiprimes(int anti)
{
	int factors = 0;
	int highFactor = 0;
	int highAnti = 0;
	int n = 1;
	int count = 0;

	while (1)
	{	
		for (int i = 1; i <= n; i++)
			if (n % i == 0) factors++;
	
		if (factors > highFactor)
		{
			highAnti = n;
			highFactor = factors;
			printf("%d: %d\n", ++count, highAnti);
		}

		if (count == anti) break;
		factors = 0;
		n++;
	}
}
