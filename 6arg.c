#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define YES     1
#define NO      0

struct tnode {
	char *word;
	int match;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char*, int, int*);
struct tnode *talloc(void);

char *strduplicate(char *);
void treeprint(struct tnode *);
int getWord(char *, int);
int compare(char *, struct tnode *, int, int *);

int bufp = 0;
char buf[MAXWORD];

int main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
    int found = NO;
    int num;

    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;
	root = NULL;

	while (getWord(word, MAXWORD) != EOF)
		if (isalpha(word[0]) && strlen(word) >= num)
			root = addtree(root, word, num, &found);
        found = NO;
	treeprint(root);
	return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int num, int *found)
{
	int cond;

	if (p == NULL)
	{
	    p = talloc();
	    p -> word = strduplicate(w);
	    p -> match = *found;
	    p -> left = p -> right = NULL;
	}
	else if ((cond = compare(w, p, num, found)) < 0)
		p -> left = addtree(p -> left, w);

	else if (cond < 0)
		p -> left = addtree(p -> left, w);

	else
		p -> right = addtree(p -> right, w);

	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL)
	{
		treeprint(p -> left);
		printf("%4d %s\n", p -> count, p -> word);
		treeprint(p -> right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strduplicate(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

int getWord(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;

	if (!isalpha(c)){
		*w = '\0';
		return c;
	}

	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= MAXWORD)
		printf("Ungetch: demasiados caracteres\n");
	else
		buf[bufp++] = c;
}