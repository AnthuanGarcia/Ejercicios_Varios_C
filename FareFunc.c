#include<stdio.h>

float convertion(int farenheit);

main(){
    int i;

    for (i = 300; i >= 0; i -= 20){
        printf("%3d %6.1f\n", i, convertion(i));
    }

}

float convertion(int farenheit){
    float celsius;

    celsius = (5.0 / 9.0) * (farenheit - 32);

    return celsius;
}