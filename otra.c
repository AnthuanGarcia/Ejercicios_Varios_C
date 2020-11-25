#include<stdio.h>

struct persona {
	int edad;
	float estatura;
	float peso;
	char* nombre;
};

int main()
{
	struct persona per;
	
	per.edad = 50;
	per.estatura = 1.23;
	per.peso = 30.452;
	per.nombre = "Joaquin";

	printf("%s tiene una edad y estatura de %d, %.2f respectivamente y pesa %.3f\n", per.nombre, per.edad, per.estatura, per.peso);
	return 0;
}
