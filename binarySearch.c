#include<stdio.h>

#define SIZE 120000

typedef unsigned long big;

big binarySearch(big x, big v[], big n);

int main()
{
    big numbers[SIZE];
    big target = 0; 
    big result;
    big i;

    for (i = 0; i < SIZE; i++)
        numbers[i] = i + 1;

    printf("Introduce el numero que buscas: ");
    scanf("%lu", &target);

    result = binarySearch(target, numbers, SIZE);

    (result == -1) ? printf("El numero no se encuentra en el conjunto")
                    :printf("El numero se encuentra en la posicion [%lu]", result);

    return 0;
}

big binarySearch(big x, big v[], big n)
{
    big low, high, mid = 0;
    int count = 0;

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        printf("%2d.- v[mid]:%6lu\tmid:%6lu\tlow:%6lu\thigh:%6lu\n", ++count, v[mid], mid, low, high);

        mid = (low + high) / 2;

        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}
