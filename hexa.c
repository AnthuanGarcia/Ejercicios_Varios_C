#include<stdio.h>

int hexToInt(int n[], int pos);
int powe(int base, int pot);

int main(int argc, char const *argv[])
{
    int i, pos = 0;
    int num[20], c;

    printf("Introduce un numero Hex: ");
    for (i = 0; i < 20 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        num[i] = c;
    }
    pos = i - 1;

    printf("%d decimales", hexToInt(num, pos));
}

int powe(int base, int pot)
{
    int p = 1;
    for (p; pot > 0; pot--)
    {
        p *= base;
    }

    return p;
}

int hexToInt(int n[], int pos)
{
    int i, trans, aum = 0;
    int pow = 0, sum = 0;

    for (i = pos; i >= 0; --i)
    {
        if (n[i] == '\n')
        {
            continue;
        }

        if (n[i] >= 48 && n[i] <= 57)
        {
            trans = 48;
            while (trans <= 57)
            {
                if (n[i] == trans)
                {
                    n[i] = aum;
                    break;
                }
                trans++;
                aum++;
            }
            aum = 0;
        }

        if (n[i] == 'A' || n[i] == 'a')
        {
             n[i] = (int)10;
        }
        else if (n[i] == 'B' || n[i] == 'b')
        {
            n[i] = (int)11;
        }

        else if (n[i] == 'C' || n[i] == 'c')
        {
            n[i] = (int)12;
        }

        else if (n[i] == 'D' || n[i] == 'd')
        {
            n[i] = (int)13;
        }

        else if (n[i] == 'E' || n[i] == 'e')
        {
            n[i] = (int)14;
        }

        else if (n[i] == 'F' || n[i] == 'f')
        {
            n[i] = (int)15;
        }

        sum += n[i] * powe(16, pow);
        pow++; 
    }

    return sum;
}