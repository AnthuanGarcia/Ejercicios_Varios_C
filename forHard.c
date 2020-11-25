#include<stdio.h>

#define SIZE 150
main()
{
    int i;
    char s[SIZE], c;

    for (i = 0; (c = getchar()) != EOF; i++)
    {
        if (c != '\n')
        {
            if (i < SIZE - 1)
            {
                s[i] = c;
            }
        }
    }
}