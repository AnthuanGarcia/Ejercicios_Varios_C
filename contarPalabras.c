#include<stdio.h>

#define IN 1    //Adentro de una palabra
#define OUT 0   //Afuera de una palabra

//Cuenta lineas, palabras, y caracteres de la entrada
main(){
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF){
        ++nc;

        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
}