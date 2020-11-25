#include<stdio.h>

void strcat(char *s, char *t);

int main(int argc, char const *argv[])
{
    char string[] = "Conche tumare ";
    char *concat_string = "qliao";

    strcat(string, concat_string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        printf("%c", string[i]);
    }
    
    return 0;
}

void strcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}
