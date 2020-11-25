#include<stdio.h>

static const int mDamm[10][10] = {
	{0, 3, 1, 7, 5, 9, 8, 6, 4, 2},
	{7, 0, 9, 2, 1, 5, 4, 8, 6, 3},
	{4, 2, 0, 6, 8, 7, 1, 3, 5, 9},
	{1, 7, 5, 0, 9, 8, 3, 4, 2, 6},
	{6, 1, 2, 3, 0, 4, 5, 9, 7, 8},
	{3, 6, 7, 4, 2, 0, 9, 5, 8, 1},
	{5, 8, 6, 9, 7, 2, 0, 1, 3, 4},
	{8, 9, 4, 5, 3, 6, 2, 0, 1, 7},
	{9, 4, 3, 8, 6, 1, 7, 2, 0, 9},
	{2, 5, 8, 1, 4, 3, 6, 7, 9, 0}
};

int controlDigit(int);
int power(int, int);
int* splitNum(int, int);

int main()
{
	int numbers[5] = {5724, 5727, 57260, 112946, 112949};

	for (int i = 0; i < 5; i++)
		controlDigit(numbers[i]) == 0 ? printf("%6d: Valido\n", numbers[i]) :\
					        printf("%6d: Invalido\n", numbers[i]);
	
	return 0;
}

int power(int a, int n)
{
	int res = 1;

	for (int i = 0; i < n; i++)
		res *= a;

	return res;
}

void reversed(int* vec, int len)
{
	int temp;
	int i = 0;

	while (i < len)
	{
		temp = vec[i];
		vec[i] = vec[len - 1];
		vec[len - 1] = temp;

		i++;
		len--;
	}
}

int* splitNum(int a, int parts)
{
	static int splitedNumber[50];
	int spl = power(10, parts);
	int i = 0;

	while (a != 0)
	{
		splitedNumber[i++] = a % spl;
		a /= 10;
	}

	splitedNumber[i] = EOF;

	reversed(splitedNumber, i);

	return splitedNumber;
}

int controlDigit(int n)
{
	int* N = splitNum(n, 1);
	int check = 0;

	for (int i = 0; N[i] != EOF; i++)
		check = mDamm[check][N[i]];

	return check;
}
