#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 20
#define MAXSIZE 3500
typedef struct Data{
	char *word;
}data;

int count;

/*int LinearSearch(char key[MAXSIZE], int n, char *k)
{
	int i;
	for (i = 0; i < n; i++)
	{
		++count;
		if(strcmp(key[i], k) == 0)
			return 1;
	}
	return 0;

}*/
/*char getWord(FILE *fp, char buf[][])
{
	int c = 0;
	int i = 0;
	while( (c = fgetc(fp) ) != EOF && !isalpha(c) )
	{}
	if (c == EOF)
	{
		return 0;
	}
	while( isalpha( c ) )
	{
		buf[i] = tolower(c);
		++i;
		c = fgetc(fp);
	}
	*buf = 0;
	return 1;
}*/

int main(int argc, char const *argv[]) {
	int method;
	int i = 0;
	int c;
	char wordlist[MAXSIZE], key[MAXWORD];
	FILE *fp;
	if( ( fp = fopen("dictionary3000.txt", "r") ) == NULL)
	{
		fprintf(stderr, "File Doesn't Exist !!!\n");
		return -1;
	}
	scanf("%s %d", key, &method);
	//int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s", wordlist);
		puts(wordlist);
		++i;
	}
	//c = LinearSearch(wordlist, i, key);
	//printf("%s\n", wordlist[3366]);
	//while ( getWord(fp, wordlist) )
		//puts(wordlist);
		//printf("%s\n", wordlist[3366]);
	//puts(wordlist);
	//printf("%d %d\n", c, count);


	return 0;
}
