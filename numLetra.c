#include<stdio.h>

void printNumber(int);

int main()
{
	int n;
	for (n = 1; n <= 100; n++)
	{
		//printf("%2d: ", n);
		printNumber(n);
	}
	return 0;
}

void printNumber(int n)
{
	int decenas = n / 10;
	int unidades = n % 10;

	char *strDecenas[9] = 
	{
		"Diez",
		"Veinte",
		"Treinta",
		"Cuarenta",
		"Cincuenta",
		"Sesenta",
		"Setenta",
		"Ochenta",
		"Noventa"
	};

	char *strUni[9] = 
	{
		"Uno",
		"Dos",
		"Tres",
		"Cuatro",
		"Cinco",
		"Seis",
		"Siete",
		"Ocho",
		"Nueve"
	};

	switch(n)
	{
		case 1:
			printf("Uno");
			break;
		case 2:
			printf("Dos");
			break;
		case 3:
			printf("Tres");
			break;
		case 4:
			printf("Cuatro");
			break;
		case 5:
			printf("Cinco");
			break;
		case 6:
			printf("Seis");
			break;
		case 7:
			printf("Siete");
			break;
		case 8:
			printf("Ocho");
			break;
		case 9:
			printf("Nueve");
			break;
		case 10:
			printf("Diez");
			break;
		case 11:
			printf("Once");
			break;
		case 12:
			printf("Doce");
			break;
		case 13:
			printf("Trece");
			break;
		case 14:
			printf("Catorce");
			break;
		case 15:
			printf("Quince");
			break;
		case 100:
			printf("Cien");
			break;
		default:
			for (int i = 0; i < 10; i++)
				if (decenas - 1 == i)
					printf("%s", strDecenas[i]);

			for (int i = 0; i < 10; i++)
				if (unidades - 1 == i)
					printf(" y %s", strUni[i]);
			break;
	}

	printf("\n");
}
