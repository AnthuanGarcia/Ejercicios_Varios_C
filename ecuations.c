#include<stdio.h>

int convert(char**);
int solution(int*);

int main(int argc, char const *argv[])
{
	int idx = 0, num = 0, len = 0;
	char numbers[50];
	int i;

	for (i = 0; argv[1][i] != '\0'; i++)
		if (argv[1][i] >= 'x' && argv[1][i] <= 'z')
			if (argv[1][i - 1] >= '0' && argv[1][i - 1] <= '9')
				continue;
			else if (argv[1][i - 1] >= 'x' && argv[1][i - 1] <= 'z')
				continue;
			else
				len++;
	
	for (i = 0; argv[1][i] != '\0'; i++)
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9') 
		{	
			numbers[idx++] = argv[1][i];
			if (argv[1][i + 1] >= '0' && argv[1][i + 1] <= '9') continue;
			len++;
		}
	}
	
	for (int i = 0; i < idx; i++)
		printf("%c ", numbers[i]);

	printf("len = %d\n", len);
}
