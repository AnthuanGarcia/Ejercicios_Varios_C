#include<stdio.h>

void printd(int n);

int main(int argc, char const *argv[])
{
    int n;
    n = 5123;

    printd(n);
    return 0;
}

void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }

    if (n / 10)
    {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}
