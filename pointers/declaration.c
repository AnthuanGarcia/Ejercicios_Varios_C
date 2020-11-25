#include<stdio.h>

int main(int argc, char const *argv[])
{
    int m = 10, n, o, *z;
    int i;

    for (i = 0; i < 25; i++)
    {
        printf("-");
    }
    printf("\n");
    z = &m;
    printf("%d\n%p\n", *z, z);

    printf("%p", &z);
    return 0;
}
