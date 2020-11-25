#include<stdio.h>

#define SIZE 120

int any(char str1[], char str2[]);

main()
{
    int i;
    char c;
    char str1[SIZE];
    char str2[SIZE];
    
    printf("Introduce una cadena: ");
    for (i = 0; i < SIZE && (c = getchar()) != EOF && c != '\n'; i++)
    {
        str1[i] = c;
    }
    str1[++i] = '\0';

    printf("Introduce otra cadena: ");
    for (i = 0; i < SIZE && (c = getchar()) != EOF && c != '\n'; i++)
    {
        str2[i] = c;
    }
    str2[++i] = '\0';

    printf("El primer match se encontro en [%d]", any(str1, str2));
}

int any(char str1[], char str2[])
{
    int i, j;

    for (i = 0; str1[i] != '\0'; i++)
    {
        for (j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
            {
                return j;
            }
        }
    }

    return -1;
}
