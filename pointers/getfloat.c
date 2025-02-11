#include<stdio.h>
#include<ctype.h>

#define SIZE 120

int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn * 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()){
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn *=  sign / power;
    if(c != EOF)
        ungetch(c);
    return c;
}

int main(int argc, char const *argv[])
{
    int i;
    float anuma[SIZE];

    for (i = 0; i < SIZE; i++)
    {
        anuma[i] = getfloat(1);
    }

    return 0;
}
