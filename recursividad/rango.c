#include<stdio.h>

int rango(int n, int i, int numeros[]);

int main(void)
{
    int n;

    printf("Introduce un numero\n");
    scanf("%d", &n);
    
    int numeros[n];

    rango(n, 0, numeros);

    return 0;
}

int rango(int n, int i, int numeros[])
{
    if (n < 0)
    {
        return 0;
    }

    numeros[i] = i;
    printf("%d ", numeros[i]);
    // printf("n = %d\ti = %d \n", n, i);

    return rango(n - 1, i + 1, numeros);
}