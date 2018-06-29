#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 20
#define MAXSIZE 3500

typedef struct Data{
	char word[MAXWORD];
}data;

int count;

int LinearSearch()
{
	int i;
	for (i = 0; i < n; i++)
	{
		++count;
		if(strcmp(key[i], k) == 0)
			return 1;
	}
	return 0;

}
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
	data wordlist[MAXSIZE];
	int method;
	int i = 0;
	//data *wordlist = (data *)malloc(sizeof(data));
	char key[MAXWORD], dictionary[MAXWORD];
	//char *wordlist[MAXSIZE];
	FILE *fp;
	if( ( fp = fopen("dictionary3000.txt", "r") ) == NULL)
	{
		fprintf(stderr, "File Doesn't Exist !!!\n");
		return -1;
	}
	//scanf("%s %d", key, &method);

	while ( (fgets(dictionary, MAXWORD, fp) ) != NULL )
	{
		strcpy(wordlist[i].word, dictionary);
		//wordlist[i].word = dictionary;
		//fscanf(fp, "%s", wordlist[i]);
		//fgets(wordlist[i], sizeof wordlist, fp);
		//strcpy(wordlist[i],	 dictionary);
		i++;
		//puts(wordlist);
	}

	printf("%s", wordlist[100].word);
	//printf("%s", wordlist[].word);
	//c = LinearSearch(wordlist, i, key);
	//printf("%s\n", wordlist[3366]);
	//while ( getWord(fp, wordlist) )
		//puts(wordlist);
		//printf("%s\n", wordlist[3366]);
	//puts(wordlist);
	//printf("%d %d\n", c, count);


	return 0;
}
