#include<stdio.h>

int len(char *s);

int main(int argc, char const *argv[])
{
    char *word = "Esta es una palabra relativamente larga";
    printf("Longitud %d", len(word));
    return 0;
}

int len(char *s)
{
    char *p = s;

    while (*p)
        p++;
    return p - s;
}
