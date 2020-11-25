#include<stdio.h>

int collatz(int n, int count);

main()
{
    int n, count = 1;

    printf("Introduce un numero: ");
    scanf("%d", &n);

    collatz(n, count);
}

int collatz(int n, int count)
{
    printf("%d:%d\n", count, n);
    if(n <= 1)
    {
        printf ("\tThe number converges to one\n");
        printf("En %d pasos converge a uno\n", count);
        return 1;
    }
    else if(n % 2 == 0)
    {
        printf("\tThe number is even\n");
        count++;
        return collatz(n / 2, count);
    }
    else
    {
        printf("\tThe number is odd\n");
        count++;
        return collatz(n * 3 + 1, count);
    }
}