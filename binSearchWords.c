#include<stdio.h>

void busqueda(char words[]);

int main(int argc, char const *argv[])
{
    char palabras[5][15] = {"Pollo", "Caralibro", "Coche", "Xilofono", "Palabra"};

    busqueda(palabras);

    return 0;
}

void busqueda(char words[])
{
    char c;

    while ((c = getchar() != EOF) && c != '\n')
    {
        
    }
    
}
