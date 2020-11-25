#include<stdio.h>

#define SIZE 4

int magicSqr(int (*arr)[], int len);
void printMatrix(int (*arr)[], int len);

int main(int argc, char const *argv[])
{
    int array[][SIZE] = {
        {16, 3, 2, 13},
        {5, 10, 11, 8},
        {9, 6, 7, 12},
        {4, 15, 14, 1}
    };
    int len = sizeof(array[0]) / sizeof(array[0][0]);

    printMatrix(array, len);

    int comprobacion = magicSqr(array, len);
    (comprobacion) ? printf("Es una matriz Magica :D\nTodas sus columnas, diagonales y filas suman %d\n", comprobacion):
                            printf("No es una matriz Magica :(\n");
    return 0;
}

int magicSqr(int arr[][SIZE], int len)
{
    int i, j;
    int sum_fila, sum_col, sum_diag, sum_diagInv;
    int sum_verify;

    sum_fila = sum_col = sum_diag = sum_diagInv = sum_verify = 0;

    for (i = 0; i < len; i++)
    {
        sum_verify += arr[0][i];
    }

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
        {
            sum_fila += arr[i][j];
            sum_col  += arr[j][i];
        }
        sum_diag    += arr[i][i];
        sum_diagInv += arr[i][len - 1 - i];
    }

    if ((sum_fila / len) == sum_verify && (sum_col / len) == sum_verify &&\
        sum_diag == sum_verify && sum_diagInv == sum_verify)
    {
        return sum_verify;
    }
    else
    {
        return 0;
    }
}

void printMatrix(int arr[][SIZE], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}