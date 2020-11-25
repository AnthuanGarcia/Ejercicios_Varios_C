#include <stdio.h>

int power(int base, int n);

main()
{
    int n = 4;
    printf("%d", power(6, n));
}

int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
    {
        p *= base;
    }

    return p;
}