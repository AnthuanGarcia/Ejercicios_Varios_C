#include <stdio.h>

void noSpaces(char *);

int main()
{
    char *str = "Hola mundo xd";

    printf("%s\n", str);

    noSpaces(str);

    printf("%s\n", str);
}

void noSpaces(char *input)
{
    for (int i = 0; input[i] != '\0'; i++)
        if (input[i] == ' ')
            input[i] = 'a';
}