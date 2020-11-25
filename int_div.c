#include<stdio.h>

int largestDiv(int n);

int main()
{
    printf("Numero: %d\n",largestDiv(20));
    return 0;
}

int largestDiv(int n)
{
    int divisores[n];
    int numerador = 0;
    int flag = 1;
    int i, puntaje = 0;

    for (i = 0; i < n; i++)
    {
        divisores[i] = i + 1;
    }

    while (flag)
    {      
        numerador++;

        for (i = 0; i < n; i++)
        {
            if (numerador % divisores[i] == 0)
            {
                puntaje++;
            }
        }

        if (puntaje == n)
        {
            flag = 0;
        }

        puntaje = 0;
    }

    printf("%d\n", numerador);
    return numerador;
}   