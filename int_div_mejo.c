#include<stdio.h>

int lcm(int a, int b);
int gcd(int a, int b);
int smallestMul(int n);

int main()
{
    int n = 20;

    printf("Numero: %d\n", smallestMul(n));

    return 0;
}

int gcd(int a, int b)
{
    if (b == 0){ return a; }
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int smallestMul(int n)
{
    int maxLCM = 1;

    for (int i = 1; i < n ; i++){
        maxLCM = lcm(maxLCM, i);
    }
    return maxLCM;
}