#include<stdio.h>

int exp(int m, int n);

main(){
    int i;

    for (i = 0; i < 15; ++i){
        printf("%d %d %d\n", i, exp(2, i), exp(-3, i));
    }

}

int exp(int base, int n){
    int i, p;

    p = 1;

    for (i = 1; i <= n; ++i){
        p *= base;
    }

    return p;
}

