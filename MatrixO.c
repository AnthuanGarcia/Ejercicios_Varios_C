#include<stdio.h>

void printMatrix();
void sum(int (*matrix)[], int (*matrix2)[], int len);
void multiply(int (*matrix)[], int (*matrix2)[],int len);
void subtraction(int (*matrix)[], int (*matrix2)[], int len);

long product[4][4] = {};

#define SIZE_MATRIX (sizeof product / sizeof(product[0]))

int main()
{
    int mtx[][SIZE_MATRIX] = {
        {4,    5,  2, 4},
        {6,   88,  4, 4},
        {8,    9,  1, 3},
        {987, 44, 11, 3}
    };

    int mtx_2[][SIZE_MATRIX] = {
        {34,   2,  5,  6},
        {102, 22,  4, 66},
        {33,  32, 31, 30},
        {1,   55, 66,  8}
    };

    int len = sizeof mtx / sizeof(mtx[0]);

    printf("Ingresa una operacion (*, +, -)\n");
    char c = getchar();

    switch (c)
    {
    case '*':
        multiply(mtx, mtx_2, len);
        break;
    case '+':
        sum(mtx, mtx_2, len);
        break;
    case '-':
        subtraction(mtx, mtx_2, len);
        break;
    default:
        printf("Opcion invalida\n");
        break;
    }

    printMatrix();

    return 0;
}

void multiply(int (*matrix)[SIZE_MATRIX], int (*matrix2)[SIZE_MATRIX], int len)
{
    int file = 0, column = 0;

    for (int k = 0; k < len; k++)
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                product[file][column] += matrix[i][j] * matrix2[j][k];
            }
            file++;
        }
        file = 0;
        column++;
    }
}

void sum(int (*matrix)[SIZE_MATRIX], int (*matrix2)[SIZE_MATRIX], int len)
{
    int file = 0, column = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            product[file][column++] = matrix[i][j] + matrix2[i][j];
        }
        column = 0;
        file++;
    } 
}

void subtraction(int (*matrix)[SIZE_MATRIX], int (*matrix2)[SIZE_MATRIX], int len)
{
    int file = 0, column = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            product[file][column++] = matrix[i][j] - matrix2[i][j];
        }
        column = 0;
        file++;
    } 
}

void printMatrix()
{
    for (int i = 0; i < SIZE_MATRIX; i++)
    {
        for (int j = 0; j < SIZE_MATRIX; j++)
        {
            printf("\t%4d\t", product[i][j]);
        }
        printf("\n");
    }
}
