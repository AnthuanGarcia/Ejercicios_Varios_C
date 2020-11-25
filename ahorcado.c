#include<stdio.h>
#include<stdlib.h>

int len(char w[]);
void game(char word[], int len);
int comprobacion(char tab[], char wor[], int len);
int lower(int c);

main()
{
    char palabra[100] = {"dont repeat yourself"};

    game(palabra, len(palabra));
}

int len(char w[])
{
    int i;
    for (i = 0; w[i] != '\0'; i++);
    return i;
}
//Verifica si dos vectores son identicos
//return 0 si son diferentes y 1 si son iguales
int comprobacion(char tab[], char wor[], int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (wor[i] != tab[i])
        {
            return 0;
        }
    }

    return 1;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; 
}

void game(char word[], int len)
{
    int i, attempts = 0, j;
    int comprobar, newAttempt;
    char c;
    char tablero[len], verificar[len];

    // display board
    for (i = 0; i < len; i++)
    {
        if (word[i] == ' ')
        {
            tablero[i] = ' ';
            printf("%c  ", tablero[i]);
        }
        else
        {
            tablero[i] = '_';
            printf("%c  ", tablero[i]);
        }
        
    }

    while (attempts != 10)
    {
        c = getchar();
        c = lower(c);

            if (c == '\n')
            {
                continue;
            }
            else
            {
                //Buscamos coincidencias del caracter introducido, en la palabra
                for (i = 0; i < len; i++)
                {
                    if (c == word[i])
                    {
                        tablero[i] = c;
                    }
                }
                /*Creamos una copia del tablero (en verificar)
                y comprobamos si verificar es identica al nuevo tablero
                si es asi, se agrega un intento*/
                newAttempt = comprobacion(verificar, tablero, len);

                if (newAttempt)
                {
                    attempts++;
                }

                for (i = 0; i < len; i++)
                {
                    verificar[i] = tablero[i];
                }
                
                system("cls");

                printf("Intentos: %d\n", attempts);
                for (j = 0; j < len; j++)
                {
                    printf("%c  ", tablero[j]);
                }
                /*Comprobamos si el tablero es identico a la palabra.*/
                comprobar = comprobacion(tablero, word, len);

                if (comprobar)
                {
                    printf("Has ganado");
                    break;
                }
            }
    }
    if (attempts >= 10)
    {
        printf("Haz perdido");
    } 
}