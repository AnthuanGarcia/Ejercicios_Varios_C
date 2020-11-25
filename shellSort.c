#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

void shellSort(int numbers[]);

int main()
{
    int i;
    int num[SIZE];

    for (i = 0; i < SIZE; i++)
    {
        num[i] = rand();
    }

    printf("Numeros en desorden\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%5d, ", num[i]);
    }

    printf("\nNumeros ordenados:\n");
    shellSort(num);

    return 0;
}

void shellSort(int numbers[])
{
    int gap, i, j, temp;

    for (gap = SIZE / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < SIZE; i++)
        {
            for (j = i - gap; j >= 0 && numbers[j] > numbers[j + gap]; j -= gap)
            {
                temp = numbers[j];
                numbers[j] = numbers[j + gap];
                numbers[j + gap] = temp;
            }
        }
    }

    for (i = 0; i < SIZE; i++)
    {
        printf("%5d, ", numbers[i]);
    }
}
