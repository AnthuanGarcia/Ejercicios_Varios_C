#include<stdio.h>

int capicuo(int);

int main()
{
	for (int i = 9000; i <= 10000; i++)
		if (capicuo(i) == i)
			printf("%d\n", i);
}

int capicuo(int n)
{
	int rem, reverse = 0;
	
	while (n != 0)
	{
		rem = n % 10;
		reverse = reverse * 10 + rem;
		n /= 10;
	}

	return reverse;
}
