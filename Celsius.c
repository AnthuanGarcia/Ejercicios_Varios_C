#include<stdio.h>
/*
Esto es un comentario multilinea??
*/
main(){

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /*Limite inferior de la tabla de temperaturas*/
    upper = 300;    /*Limite superior de la tabla de temperaturas*/
    step = 20;      /*Paso de los grados Celsius*/

    fahr = lower;

    printf("Tabla de temperaturas\n");
    while (fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f%6.1f\n", fahr, celsius);
        fahr+= step;
    }
    
}