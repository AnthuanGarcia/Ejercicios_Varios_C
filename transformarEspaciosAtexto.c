#include<stdio.h>

main(){

    int entrada = 0;

    while ((entrada = getchar()) != EOF){
        if (entrada == '\t'){
            printf("\\t\n");
        }

        if (entrada == ' '){
            printf("esp\n");
        }

        if (entrada == '\\'){
            printf("\\\\\n");
        }
    }
}