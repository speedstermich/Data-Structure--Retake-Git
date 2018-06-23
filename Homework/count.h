#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 32
#define MAXSIZE 1024
//#define LETTER 'a'
//#define DIGIT '0'

struct Node {
	char word[MAXWORD];
	int count;
	struct Node *link;
};
struct Node *Wordlist = NULL;

char getWord(FILE *fp, char *buf)
{
	int c = 0;
	while( (c = fgetc(fp) ) != EOF && !isalpha(c) )
	{}
	if (c == EOF)
	{
		return 0;
	}
	while( isalpha( c ) )
	{
		*buf = tolower(c);
		++buf;
		c = fgetc(fp);
	}
	*buf = 0;
	return 1;
}

int insertWord(struct Node *p,  char *w)
{
	struct Node *q;

	q = (struct Node *)malloc(sizeof(struct Node));
	if (q == NULL)
		return -1;
	strcpy(q -> word, w);
	q -> count = 1;
	q -> link = NULL;

	if (Wordlist == NULL)
		Wordlist = q;
	else if (p == NULL)
	{
		q -> link = Wordlist;
		Wordlist = q;
	}
	else
	{
		q ->  link = p -> link;
		p -> link = q;
	}
return 0;
}

int searchWord(char *w)
{
	struct Node *p, *q = NULL;
	for (p = Wordlist; p != NULL; q = p, p = p -> link)
	{
		if (strcmp (w, p -> word) < 0)
			break;
		else if (strcmp(w, p -> word) == 0)
		{
			p -> count++;
			return 0;
		}
	}
	return insertWord(q, w);
}
