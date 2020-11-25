#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000

void qsort1(int v[], int left, int right);

int main(int argc, char const *argv[])
{
    int i;
    int num[SIZE];

    for (i = 0; i < SIZE; i++)
    {
        num[i] = rand();
    }

    printf("Numeros desordenados\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d,", num[i]);
    }

    qsort1(num, 0, SIZE - 1);

    printf("\nNumeros ordenados\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d, ", num[i]);
    }
    return 0;
}

void qsort1(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    
    swap(v, left, last);
    qsort1(v, left, last - 1);
    qsort1(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
