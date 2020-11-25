#include<stdio.h>

int lower(int c);

main()
{
    int i, lenght;
    char palabra[30], c;

    for (i = 0; (c = getchar()) != EOF && i < 30; i++)
    {
        palabra[i] = c;
    }

    lenght = i;

    for (i = 0; i < lenght; i++)
    {
        printf("%c", lower(palabra[i]));
    }

}

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 'a' - 'A';
    }
    else
    {
        return c;
    }
    
}