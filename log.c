#include <stdio.h>

double loga(double n, double base);
double power(double a, int n);

int main()
{
    int n;
    int base;

    printf("Introduce a:\n");
    scanf("%d", &n);

    printf("Introduce la base:\n");
    scanf("%d", &base);

    printf("\nEl logaritmo base %d de %d es %lf\n\n", base, n, loga(n, base));

    return 0;    
}

double power(double a, int n)
{
    if (n == 0)
        return 1.0;

    if (n < 0)
        return 1 / power(a, -(n - 1)) * a;

    if (!(n % 2 == 0))
        return power(a, n - 1) * a;

    if (n % 2 == 0)
    {
        double y = power(a, n / 2);
        return y * y;
    }
}

double loga(double n, double base)
{
    double caracteristica = 0;
    double mantira = 0;
    int c = 1;

    while (n > base)
    {
        n /= base;
        caracteristica++;
    }

    while (c != 10)
    {
        // n se eleva con respecto al sistema numerico que se este utilizando (en este caso decimal)
        n = power(n, 10);

        while (n > base)
        {
            n /= base;
            mantira++;
        }

        mantira /= power(10, c);
        caracteristica += mantira;
        mantira = 0;
        c++;
    }

    return caracteristica;
}
