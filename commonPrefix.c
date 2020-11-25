#include<stdio.h>
#include<string.h>

char *longestPrefix(char *strs[], int strSize);
void printVector(char *strs[], int len);

char prefix[10];

int main()
{
	char *words[] = {
		"flower",
		"flow",
		"flight"
	};

	char *words2[] = {
		"dog",
		"racecar",
	    "car"
	};

	char *words3[] = {
		"precio",
		"precario",
		"preciso",
		"presa",
		"prestamo",
		"preso"
	};

	int len = sizeof words / sizeof(words[0]);

	char *pref;
	longestPrefix(words, len);
	pref = &prefix[0];

	printVector(words, len);
	printf("%s\n", pref);

	return 0;
}

void printVector(char *strs[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%s ", strs[i]);
	printf("\n");
}

char *longestPrefix(char **strs, int strSize)
{
	char *ptrPrefix = &prefix[0];
	int c = 0;

	for (int i = 1; i < strSize; i++)
	{
		for (int j = 0; strs[i][j] != '\0'; j++)
		{
			if (strs[0][i - 1] == strs[i][j])
			{
				prefix[c] = strs[i][j];
				c++;
			}
		}
	}

	return ptrPrefix;
}
