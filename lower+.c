#include<stdio.h>

int lowerPlus(int c);

main()
{
    int i;
    char palabra[50], c;

    for (i = 0; (c = getchar()) != EOF && i < 50 && c != '\n'; i++)
    {
        palabra[i] = c;
    }

    palabra[++i] = '\0';

    for (i = 0; palabra[i] != '\0'; i++)
    {
        printf("%c", lowerPlus(palabra[i]));
    }

}

int lowerPlus(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}