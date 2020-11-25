#include<stdio.h>

void magic(int);
void concat(char*, char*);
void copystr(char*, char*);

int main()
{
	for (int i = 0; i <= 9; i++)
		magic(i);

	return 0;
}

void concat(char *s1, char *s2)
{
	int i, j;
	i = j = 0;

	while (s1[i] != '\0') i++;

	while((s1[i++] = s2[j++]) != '\0');
}

void copystr(char *s, char *t)
{
	int i = 0;

	while ((s[i] = t[i]) != '\0') i++;
}

int slen(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

void magic(int a)
{
	int units = a % 10;;
	int tens = a / 10;
	int countC = 0;
	char temp[50];

	char *strUnits[10] = {
		"Zero",
		"One",
		"Two",
		"Three",
		"Four",
		"Five",
		"Six",
		"Seven",
		"Eigth",
		"Nine"
	};

	char *strSpecial [10] = {
		"Ten",
		"Eleven",
		"Twelve",
		"Thirty",
		"Fourteen",
		"Fifteen",
		"Sixteen",
		"Seventeen",
		"Eighteen",
		"Nineteen"
	};

	char *strTens[9] = {
		"Twenty",
		"Thirty",
		"Forty",
		"Fifty",
		"Sixty",
		"Seventy",
		"Eighty",
		"Ninety",
		"hundred"
	};
	
	if (a == 4) 
	{
		printf("Four is Magic\n");
		return;
	}

	if (a < 10)
		//temp = strUnits[i];
		copystr(temp, strUnits[a]);
	else if (a >= 10 && a < 20)
		//temp = strSpecial[i - 10];
		copystr(temp, strSpecial[a - 10]);
	
	if (tens >= 2 && units < 1)
		//temp = strTens[tens - 2];
		copystr(temp, strTens[tens - 2]);
	else if (tens >= 2 && units >= 1)
	{
		copystr(temp, strTens[tens - 2]);
		concat(temp, " ");
		concat(temp, strUnits[units]);
	}
	
	countC = slen(temp);

	if (countC < 10)
		printf("%s is %s, ", temp, strUnits[countC]);
	else if (countC >= 10 && countC < 20)
		printf("%s is %s, ", temp, strSpecial[countC - 10]);

	while (countC != 4)
	{
		if (countC < 10)
		{
			copystr(temp, strUnits[countC]);
			countC = slen(temp);
		}
		else if (countC >= 10 && countC < 20)
		{
			copystr(temp, strSpecial[countC - 10]);
			countC = slen(temp);
		}
		if (countC < 10)
			printf("%s is %s, ", temp, strUnits[countC]);
		else if (countC >= 10 && countC < 20) 
			printf("%s is %s, ", temp, strSpecial[countC - 10]);
	}

	printf("Four is magic\n");
}
