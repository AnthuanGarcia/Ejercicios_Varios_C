#include <stdio.h>

typedef char* String;

int main()
{
	// C no verifica datos de tipo Int y Char, le da igual
	int arr['A'];

	String palabra = "Esto es una cadena :D";
	char word[21]  = "This is a String :O?";
	char *w	       = "????";

	int len = sizeof(arr) / sizeof(arr[0]);

	int ptr[10] = {1, 2, 3, 5, 6, 7, 8, 9, 10, 4};

	//printf("La longitud del arreglo es: %d\n", len);
	//printf("%s\n", palabra);
	//printf("%s\n", word);
	//printf("%s\n", w);

	//for (int i = 0; i < 500; i++)
	//	printf("%p ", ptr[i]);
	printf("%u\n", w);
	printf("%p\n", w);

	return 0;
}
