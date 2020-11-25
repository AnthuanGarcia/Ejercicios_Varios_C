#include<stdio.h>

int main(int argc, char const *argv[])
{
    int m = 30;
    int *ab = &m;

    printf("La direccion de m es %p\n", &m);
    printf("El valor de m es %d\n", m);

    ab = &m;
    printf("ab = &m\n");
    printf("La direccion de ab es %p\n", &ab);
    printf("El valor de ab es %d\n", *ab);

    m = 69; // ab esta apuntando a m
    printf("\n69 es asignado a m\n");
    printf("La direccion de ab es %p\n", &ab);
    printf("El valor de ab es %d\n", *ab);

    *ab = 7;
    printf("\n7 es asignado a ab\n");
    printf("La direccion de m es %p\n", &m);
    printf("El valor de m es %d", m);

    return 0;
}
