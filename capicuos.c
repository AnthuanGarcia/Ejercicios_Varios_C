#include<stdio.h>

int capicuo(int n);

main()
{
    int n, reverse;

    printf("Introduce un numero:\n");
    scanf("%d", &n);

    reverse = capicuo(n);

    (n == reverse) ? printf("Es capicuo :D") : printf("No es capicuo :(");
}

int capicuo(int n)
{
    int reverse = 0, rem;

    while (n != 0)
    {
        rem = n % 10;
        reverse = reverse * 10 + rem;
        n /= 10;
    }

    return reverse;
}
