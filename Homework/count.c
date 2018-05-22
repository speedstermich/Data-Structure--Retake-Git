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

//int getWord (FILE *fp, char w[]);
//char type(int c);
char getWord (FILE *fp, char *buf);
int searchWord(char *w);
int insertWord(struct Node *p, char *w);

int main(int argc, char const *argv[]) {
	struct Node *p;
	char word[MAXWORD];
	FILE *fp;

	if ((fp = fopen("article.txt", "r")) == NULL)
	{
		fprintf(stderr, "file can't open !\n");
		return -1;
	}

	while (getWord (fp, word))
		if (searchWord (word) == -1)
		{
			fprintf(stderr, "Wordlist is full\n");
			return  -1;
		}

	for (p = Wordlist; p != NULL; p = p -> link )
	{
		printf("%s %d\n", p ->word, p -> count);
	}

fclose(fp);
return 0;
}

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
/*int getWod(FILE *fp, char w[])
{
int c, i = 0;
//char word[MAXWORD] = w;
while ((c = fgetc(fp)) != EOF && !isalpha(c))
	if(c == EOF)
		return c;
	else
		continue;
w [i++] = c;
while ((c = fgetc(fp)) != EOF && !isalpha(c))
{
	if (type(c) != LETTER || type(c) != DIGIT)
		break;
	w[i++] = tolower(c);
}
w[i] = 0;
return 1;
}*/

/*int getWord (FILE *fp, char w[])
{
	int c, i = 0;
	//char word[MAXWORD] = w;
	while (type(c = fgetc(fp)) != LETTER)
		if(c == EOF)
			return c;
		else
			continue;
	w [i++] = c;
	while ((c = fgetc(fp)) != EOF && !isalpha(c))
	{
		if (type(c) != LETTER || type(c) != DIGIT)
			break;
		w[i++] = tolower(c);
	}
	w[i] = 0;
	return 1;

	//while (fscanf(fp, "%s", w) != EOF);
}*/

/*char type(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return(LETTER);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		// tolower(c);
		return (LETTER);
		//return (LETTER);
	}
	else if (c >= '0' && c <= '9')
	{
		return (DIGIT);
	}
	else return (c);
}*/
