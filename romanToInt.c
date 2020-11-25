#include<stdio.h>

int romanToInt(char romanNumber[])
{
    int i;
    int numberB10 = 0;

    for (i = 0; i < 9; i++)
    {
        if (romanNumber[i] == 'I')
        {
            if (romanNumber)
        }
    }
    return numberB10;
}

main()
{
    char roman[9];
    char c;
    int i;

    for (i = 0; i <= 8 && c != EOF; i++)
    {
        c = getchar();
        roman[i] = c;
    }

    printf("%d", romanToInt(roman));
}

        // if (romanNumber[i] == 'I')
        // {
        //     if (repetions < 3)
        //     {
        //         numberB10 += 1;
        //     }
        //     if (romanNumber[i] == romanNumber[i + 1])
        //     {
        //         repetions += 1;
        //     }
        //     else
        //     {
        //         repetions = 0;
        //     }
        // }
