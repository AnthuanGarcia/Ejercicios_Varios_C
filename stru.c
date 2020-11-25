#include<stdio.h>

struct persona {
	int edad;
	float estatura;
    char* nombre;	
};

void llenarStruct(struct persona *gente)
{
	gente->edad = 40;
	gente->estatura = 1.55;
	gente->nombre = "Joaquin";
}

int main()
{
	struct persona p;

	p.edad = 22;
	p.estatura = 1.97;
	p.nombre = "El pepe";
	
	printf("La edad de %s es %d, y mide %.2f mts\n", p.nombre, p.edad, p.estatura);

	llenarStruct(&p);

	printf("La edad de %s es %d, y mide %.2f mts\n", p.nombre, p.edad, p.estatura);

	return 0;
}
