#include <stdio.h>

#define IN 1
#define OUT 0

main(){
    int c;
    int state = OUT;

    while ((c = getchar()) != EOF){

        if (c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
            printf("\n");
        }

        else if (state == OUT){
            state = IN;
        }

        printf("%c", c);
    }
}