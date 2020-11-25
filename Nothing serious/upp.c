#include<stdio.h>

int upper(char c);

int main()
{
	for (int i = 'a'; i <= 'z'; i++)
		printf("%c ", i);

	printf("\n\n");

	for (int i = 'a'; i <= 'z'; i++)
		printf("%c ", upper(i));

	printf("\n");

	return 0;
}

int upper(char c)
{
	return (c >= 'a' && c <= 'z') ? c + 'A' - 'a' : c;
}
