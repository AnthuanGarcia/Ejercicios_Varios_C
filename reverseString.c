#include <stdio.h>

void reverseStr(char[]);

int main()
{
	char word[] = "as?d";

	printf("%s\n", word);

	reverseStr(word);

	printf("%s\n", word);

	return 0;
}

void swap(char c, char p, char w[])
{
	int temp;

	temp = w[c];
	w[c] = w[p];
	w[p] = temp;
}

void reverseStr(char str[])
{
	int j = 0;
	int i;
	for (i = 0; str[i] != '\0'; i++); --i;

	while (j < i) swap(j++, i--, str);
}
