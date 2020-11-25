#include<stdio.h>

int main()
{
	int n = 0;
bucle:
	printf("Estoy dentro de un GOTO xd\n");
	n++;

	if (n == 10) goto salir;

	goto bucle;

salir:
	printf("He salido de un GOTO :O\n");

	return 0;

}
