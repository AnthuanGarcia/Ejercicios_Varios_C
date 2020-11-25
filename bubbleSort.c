#include<stdio.h>

int *bubbleSort(int *arr, int len);

int main()
{
    int array[] = {
        1, 4, 2, 8, 345, 123, 43, 32, 5643, 63, 123, 43, 2, 55, 1, 234, 92
    };
    int len = sizeof(array) / sizeof(array[0]);

    printf("Desordenado:\n");
    for (int i = 0; i < len; i++)
    {
        printf(" %d ", array[i]);
    }
    printf("\tLongitud = %d", len);
    printf("\n");

    int *sortedArr = bubbleSort(array, len);

    printf("Ordenado:\n");
    for (int i = 0; i < len; i++)
    {
        printf(" %d ", sortedArr[i]);
    }
    printf("\tLongitud = %d", len);
    printf("\n");

    return 0;
}

int *bubbleSort(int *arr, int len)
{
    int temp;

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            temp = arr[i];
            if (temp > arr[j])
            {
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr;
}