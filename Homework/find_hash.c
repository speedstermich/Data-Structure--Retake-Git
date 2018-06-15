#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 20
#define MAXSIZE 3500
int count;

/*int LinearSearch(char key[], int n, char k)
{

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
	char wordlist[MAXSIZE][MAXWORD], key[MAXWORD];
	FILE *fp;
	if( ( fp = fopen("dictionary3000.txt", "r") ) == NULL)
	{
		fprintf(stderr, "File Doesn't Exist !!!\n");
		return -1;
	}
	scanf("%s %d", key, &method);
	//int i = 0;
	while (fgets(wordlist[i], sizeof wordlist[i], fp) != 0)
	{
		++i;
	}
	printf("%s\n", wordlist[3366]);
	//while ( getWord(fp, wordlist) )
		//puts(wordlist);
		//printf("%s\n", wordlist[3366]);

	//scanf("%s %d", key, &method);

	return 0;
}
