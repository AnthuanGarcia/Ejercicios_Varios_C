#include<stdio.h>

main(){
    int estilo = 0;
    int conTab = 0;
    int contEsp = 0;
    int contLin = 0;

    while ((estilo = getchar()) != EOF){

        if (estilo == '\t'){
            conTab++;
        }

        if (estilo == '\n'){
            contLin++;
        }

        if (estilo == ' '){
            contEsp++;
        }
    }

    printf("%d\t%d\t%d\n",conTab, contLin, contEsp);
}