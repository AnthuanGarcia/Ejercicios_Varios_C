#include<stdio.h>

void numero(int n);

int main(int argc, char const *argv[])
{
    int n;

    printf("Introduce un numero:\n");
    scanf("%d", &n);

    numero(n);

    return 0;
}

void numero(int n)
{
    int i;

    char decenas[10][15] = {"Diez", "Veinte", "Treinta", "Cuarenta", "Cincuenta",\
                            "Sesenta", "Setenta", "Ochenta", "Noventa"};

    char unidades[10][10] = {"Uno", "Dos", "Tres", "Cuatro", "Cinco",\
                            "Seis", "Siete", "Ocho", "Nueve", "Diez"};

    if (n < 16)
    {
        switch (n)
        {
        case 1:
            printf("Uno");
            break;
        case 2:
            printf("Dos");
            break;
        case 3:
            printf("Tres");
            break;
        case 4:
            printf("Cuatro");
            break;
        case 5:
            printf("Cinco");
            break;
        case 6:
            printf("Seis");
            break;
        case 7:
            printf("Siete");
            break;
        case 8:
            printf("Ocho");
            break;
        case 9:
            printf("Nueve");
            break;
        case 10:
            printf("Diez");
            break;
        case 11:
            printf("Once");
            break;
        case 12:
            printf("Doce");
            break;
        case 13:
            printf("Trece");
            break;
        case 14:
            printf("Catorce");
            break;
        case 15:
            printf("Quince");
            break;
        }
    } 
    else
    {
        int idx_unidades;
        for (i = 1; i <= 10; i++)
        {
            if ((n / 10) == i)
            {
                for (int j = 0; decenas[i - 1][j] != '\0'; j++)
                {
                    printf("%c", decenas[i - 1][j]);
                }

                if (n % (i*10) > 0)
                {
                    idx_unidades = n % (i*10);
                    printf(" y ");
                    for (int k = 0; unidades[idx_unidades - 1][k] != '\0'; k++)
                    {
                        printf("%c", unidades[idx_unidades - 1][k]);
                    }  
                }  
            }
        }
    }   
}
