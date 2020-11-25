#include<stdio.h>

//Octal
#define VTAB '\013'
#define BELL '\007'

//Hexadecimal
#define VTEB '\xb'
#define BOLL '\x7'

main()
{
    int num = 'A' + 'A';

    printf("%d\n", num);
    printf("%d \n", VTAB);
    printf("%d \n", BELL);
    printf("%d \n", VTEB);
    printf("%d \n", BOLL);
}