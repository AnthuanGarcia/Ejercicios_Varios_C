#include <stdio.h>

int main()
{
	int x = 0;
sentencia:
	printf("EStoy dentro de un goto\n");
	if (x == 10) goto salir;
	x++;
	goto sentencia;

salir:
	printf("He salido del infierno :O\n");
	return 0;
}
