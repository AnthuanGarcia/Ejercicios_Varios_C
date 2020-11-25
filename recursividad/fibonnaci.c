#include<stdio.h>

int Fibonacci(int a, int b, int c, int n);

int main(int argc, char const *argv[])
{
    int n;
    int a = 0, b = 1, c = a + b;

    printf("Introduce los numeros de Fibonacci que quieres:\n");
    scanf("%d", &n);

    Fibonacci(a, b, 0, n);

    return 0;
}

int Fibonacci(int a, int b, int c, int n)
{
    if (n == 0)
    {
        return 0;
    }
    n--;

    printf("%d\n", c);

    //c = a + b;
    a = b;
    b = c;

    Fibonacci(a, b, a + b, n);
}
