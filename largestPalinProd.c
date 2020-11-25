#include<stdio.h>

int capicuo(int n);
int power(int base, int pow);
int largestPalindromeProduct(int n);

int main(int argc, char const *argv[])
{
    int n = 4;

    printf("El numero es: %d\n", largestPalindromeProduct(n));
    return 0;
}

int power(int base, int pow)
{
    int res = 1;

    for (int i = 0; i < pow; i++){ 
        res *= base; 
    }

    return res;
}

int capicuo(int n)
{
    int volteado = 0, rem;

    while (n != 0){
        rem = n % 10;
        volteado = (volteado * 10) + rem;
        n /= 10;
    }

    return volteado;
}

int largestPalindromeProduct(int n)
{
    int limit = power(10, n);
    int product = 0, rev_product, mayor = 0;

    for (int i = 0; i < limit; i++)
    {
        for (int j = i + 1; j < limit; j++)
        {
            product = i * j;
            rev_product = capicuo(product);

            if (product == rev_product){
                if (product > mayor){
                    mayor = product;
                }
            }
        }
    }
    return mayor;
}