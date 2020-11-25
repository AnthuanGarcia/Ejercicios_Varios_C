#include<stdio.h>

int mod(int, int);
int unmod(int, int);

int main()
{
	int xd =  mod(64578, 50)
	printf("%d\n", xd);

	int p = unmod(xd, 50);
	printf("%d\n", p);
	return 0;
}

int unmod(int result, int modi)
{
	
}

int mod(int n, int a)
{
	int sum = 0;

	if (a > n)
        sum = 0;
    else
        while (sum <= n)
            sum += a;   
    
    if (sum > n)
        sum -= a;

	return n - sum;
}
