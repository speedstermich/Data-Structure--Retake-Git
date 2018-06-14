#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORD 32
#define MAXSIZE 1024
struct BSTnode{
	char word[MAXWORD];
	struct BSTnode *right, *left;
};

char GetWord(FILE *fp, char *buf)
{
	int c = 0;
	while( (c = fgetc(fp) ) != EOF && !isalpha(c) )
	{}
	if(c == EOF)
	{
		return 0;
	}
	while ( isalpha(c) )
	{
		*buf = tolower(c);
		++buf;
		c = fgetc(fp);
	}
	*buf = 0;
	return 1;
}

int main(int argc, char const *argv[]) {
	FILE *fp;
	char word[MAXWORD];
	if((fp = fopen("in.txt", "r")) == NULL)
	{
		fprintf(stderr, "File Doesn't Exist !!\n");
		return -1;
	}

	while(GetWord(fp, word))
	{
		
	}
	return 0;
}
