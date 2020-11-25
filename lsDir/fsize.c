#ifndef DIRSIZ
#define DIRSIZ 14
#endif

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include"dirent.h"

#define MAX_PATHA 1024

struct direct {
    ino_t d_ino;
    char d_name[DIRSIZ];
};

void fsize(char *);

char *name;
struct stat stbuf;
//int stat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char*));
int fstat(int fd, struct stat *);

int main(int argc, char **argv)
{
	if (argc == 1)
		fsize(".");
	else
		while(--argc > 0)
			fsize(*++argv);

	return 0;
}

void fsize(char *name)
{
	struct stat stbuf;

	if (stat(name, &stbuf) == -1)
	{
		fprintf(stderr, "fsize: No se puede accerder a %s\n", name);
		return;
	}

	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);

	printf("%8ld %s\n", stbuf.st_size, name);
}

DIR *opendir(char *dirname)
{
	int fd;
	struct stat stbuf;
	DIR *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1
	|| fstat(fd, &stbuf) == -1
	|| (stbuf.st_mode & S_IFMT) != S_IFDIR
	|| (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
		return NULL;

	dp -> fd = fd;
	return dp;
}

void closedir(DIR *dp)
{
	if (dp)
	{
		close(dp -> fd);
		free(dp);
	}
}

Dirent *readdir(DIR *dp)
{
	struct direct dirbuf;
	static Dirent d;

	while (read(dp -> fd, (char*) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf))
	{
		if (dirbuf.d_ino == 0)
			continue;

		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIRSIZ);
		d.name[DIRSIZ] = '\0';
		return &d;
	}

	return NULL;
}

void dirwalk(char *dir, void (*fcn)(char*))
{
	char name[MAX_PATHA];
	Dirent *dp;
	DIR *dfd;

	if ((dfd = opendir(dir)) == NULL)
	{
		fprintf(stderr, "dirwalk: No se puede abrir %s\n", dir);
		return;
	}

	while ((dp = readdir(dfd)) != NULL)
	{
		if (strcmp(dp -> name, ".") == 0
		|| strcmp(dp -> name, ".."))
			continue;

		if (strlen(dir) + strlen(dp -> name) + 2 > sizeof(name))
			fprintf(stderr, "dirwalk: Los nombres de %s %s son demasiado largos\n", dir, dp->name);

		else
		{
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}
