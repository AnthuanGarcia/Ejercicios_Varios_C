#include<stdio.h>

main(){
    int c, ni;

    ni = 0;

    while((c = getchar()) != EOF){
        if(c == '\n'){ //10 es quivalente a '\n' y viceversa
            ++ni;
        }
        printf("%d\n", ni); 
    }
}