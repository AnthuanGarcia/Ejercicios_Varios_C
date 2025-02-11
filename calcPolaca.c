#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

main()
{
    int type;
    double op2 = 0.0, op1 = 0.0, sum = 0.0;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("Errrooor: Zero division\n");
            break;
        case '%':
            op2 = pop();
            op1 = pop();

            if (op2 > op1)
            {
                sum = 0;
            }
            else
            {
                while (sum <= op1)
                {
                    sum += op2;
                }   
            }

            if (sum > op1)
            {
                sum -= op2;
            }
            push(op1 - sum);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Errroor: Unknow mama %s\n", s);
            break;
        }
    }
}

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("Error: Stack lleno %g\n", f);
    }
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("Error: Stack vacio\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    
    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: Muchos caracteres >:(\n");
    else
    {
        buf[bufp++] = c;
    }
}
