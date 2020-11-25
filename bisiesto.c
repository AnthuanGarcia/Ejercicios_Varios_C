#include<stdio.h>

main()
{
    int year;

    printf("Introduce un ano: \n");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        printf("El ano %d es bisiesto", year);
    }
    else
    {
        printf("El ano %d no es bisiesto", year);
    }
    
}