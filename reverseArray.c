#include<stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char s[]);

main()
{
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0){
        reverse(line);
        printf("%s", line);
    }
}

int getLine(char s[], int lim)
{
    int c, i, j;

    j = 0;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 2){
            s[j] = c;
            ++j;
        }

    if (c == '\n'){
        s[j] = c;
        ++j;
        ++i;
    } 
    s[j] = '\0';
    return i;
}

void reverse(char str[])
{
    int j, i;
    char temp;

    i = 0;
    while (str[i] != '\0')
        ++i;
    --i;

    if (str[i] == '\n')
        --i;
    
    printf("%d\n", i);

    j = 0;
    while (j < i){
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        --i;
        ++j;
    }

}
