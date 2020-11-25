#include <stdio.h>

float resta(float n, float n2);
float suma(float n, float n2);
float division(float n, float n2);
float multiplicacion(float n, float n2);

main()
{
    char opcion;
    float n, n2;

    printf("Introduce una opcion de opercion XD:\n");
    opcion = getchar();
    
    printf("Introduce un numero:");
    scanf("%f", &n);
    printf("Introduce otro numero:");
    scanf("%f", &n2);

    if (opcion == 's')
    {
        printf("\nLa suma es: %f", suma(n, n2));
    }
    else if (opcion == 'r')
    {
        printf("\nLa resta es: %f", resta(n, n2));
    }
    else if (opcion == 'd')
    {
        printf("\nLa division es: %f", division(n, n2));
    }
    else if (opcion == 'm')
    {
        printf("\nLa multiplicacion es: %f", multiplicacion(n, n2));
    }

}

float suma(float n, float n2)
{
    return n + n2;
}

float resta(float n, float n2)
{
    return n - n2;
}

float division(float n, float n2)
{
    return n / n2;
}

float multiplicacion(float n, float n2)
{
    return n * n2;
}