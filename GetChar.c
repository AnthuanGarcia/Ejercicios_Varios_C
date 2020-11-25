#include<stdio.h>

main(){
    int c, value = EOF;

    printf("%d", EOF);

    while((c = getchar()) != value){
        putchar(c);
        printf("\n%d%3d\n",value,c);

        /*value+= 1;*/
    }
    printf("Si sale?");

}