#include<stdio.h>

void insert(int *arr, int right, int val);
void insertion(int *arr, int len);

int main()
{
    int arreglo[] = {
        22, -1, -2, 0, 2, 1, 827, 9999, -234, -4 , 4, 3, 45, 26
    };
    int len = sizeof arreglo / sizeof(arreglo[0]);

    printf("Arreglo desacomodado:\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    printf("\n");
    printf("Arreglo acomodado:\n");
    insertion(arreglo, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}

void insert(int arr[], int right, int val)
{
    int j;

    for (j = right; j >= 0 && arr[j] > val; j--)
    {
        arr[j + 1] = arr[j];
    }

    arr[j + 1] = val;
}

void insertion(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        insert(arr, i - 1, arr[i]);
    }
}