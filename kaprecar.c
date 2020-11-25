#include <stdio.h>

int *splitNumber(int, int);
int power(int, int);
void sorting(int *);
int kaprekar(int);

int main()
{
    int n;

    printf("Introduce un numero de 4 cifras\n");
    scanf("%d", &n);

    printf("%d\n", kaprekar(n));

    return 0;
}

int power(int a, int n)
{
    int res = 1;

    for (int i = 0; i < n; i++)
        res *= a;

    return res;
}

int *splitNumber(int a, int partes)
{
    static int splitedNumber[4] = {0, 0, 0, 0};
    int spl = power(10, partes);
    int i = 0;

    while (a != 0)
    {
        splitedNumber[i++] = a % spl;
        a /= spl;
    }

    splitedNumber[i] = EOF;

    return splitedNumber;
}

void sorting(int *vec)
{
	int len = 4, temp;
	
	for (int gap = len / 2; gap > 0; gap /= 2)
		for (int i = gap; i < len; i++)
			for (int j = i - gap; j >= 0 && vec[j] > vec[j + gap]; j -= gap)
			{
				temp = vec[j];
				vec[j] = vec[j + gap];
				vec[j + gap] = temp;
			}
}

int kaprekar(int kaprecar)
{
    int mayor = 0, menor = 0, potencia = 0, pasos = 0;
    int *splitN;

    while (kaprecar != 6174)
    {
	    if (kaprecar == 999) kaprecar *= 10;

        splitN = splitNumber(kaprecar, 1);
        sorting(splitN);

        for (int i = 0, j = 3; splitN[i] != EOF; i++, j--)
        {
            potencia = power(10, j);
            menor += splitN[i] * potencia;
            mayor += splitN[j] * potencia;
        }

        kaprecar = mayor - menor;
        printf("%1d.- %4d - %4d = %4d\n", ++pasos, mayor, menor, kaprecar);
        mayor = 0;
        menor = 0;
    }
    
    return kaprecar;
}
