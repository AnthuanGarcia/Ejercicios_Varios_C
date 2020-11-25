#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define HASH_SIZE 101
#define MAXWORD 100

static struct nlist *hashtab[HASH_SIZE];
unsigned hash(char *);
struct nlist *lookup(char *);

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL)
	{
		np = (struct nlist *) malloc(sizeof(*np));

		if (np == NULL || (np -> name = strdup(name)) == NULL)
			return NULL;

		hashval = hash(name);
		np -> next = hashtab[hashval];
		hashtab[hashval] = np;
	} 
	else
		free((void *) np -> defn);

	if ((np -> defn = strdup(defn)) == NULL)
		return NULL;

	return np;
}

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval % HASH_SIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np -> next)
		if (strcmp(s, np -> name) == 0)
			return np;
	return NULL;
}

int bufp = 0;
char buf[MAXWORD];

int main()
{
	struct nlist *p;
	char *names[4] = {
		"hola",
		"Prueba",
		"No se como funciona",
		"es"
	};

	char *defs[4] = {
		"s",
		"s",
		"es",
		"Polla"
	};

	p = install(names[0], defs[0]);

	for (int n = 0; n < 4; n++)
		if (p -> defn > 0 && p -> name > 0)
			printf("%s\t%s\n",  p -> name, p -> defn);

	return 0;
}

// int getWord(char *word, int lim)
// {
// 	int c, getch(void);
// 	void ungetch(int);
// 	char *w = word;

// 	while (isspace(c = getch()))
// 		;
// 	if (c != EOF)
// 		*w++ = c;

// 	if (!isalpha(c)){
// 		*w = '\0';
// 		return c;
// 	}

// 	for ( ; --lim > 0; w++)
// 		if (!isalnum(*w = getch())) {
// 			ungetch(*w);
// 			break;
// 		}
// 	*w = '\0';
// 	return word[0];
// }

// int getch(void)
// {
// 	return (bufp > 0) ? buf[--bufp] : getchar();
// }

// void ungetch(int c)
// {
// 	if (bufp >= MAXWORD)
// 		printf("Ungetch: demasiados caracteres\n");
// 	else
// 		buf[bufp++] = c;
// }
