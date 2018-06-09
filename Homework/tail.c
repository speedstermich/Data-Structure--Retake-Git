#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 81
#define DEFLINES 10
struct Node{
	char *line;
	struct Node *next;
};

int main(int argc, char *argv[])
{
	char currentline[MAXLEN], *filename;
	int n = DEFLINES;
	int i;
	struct Node *first, *pointer;
	FILE *fp;

	//read command from command prompt / terminal
	if(argc == 3 && argv[1][0] == '-')
	{
		n = atoi(argv[1] + 1);
		filename = argv[2];
	}
	else if (argc == 2)
	{
		filename = argv[1];
	}
	else
	{
		printf("Usage: tail [-n] filename\n");
		return(1);
	}
	//open file, fp read
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Can't open file: %s\n", filename);
		return (-1);
	}
	//request space for first pointer
	first = pointer = (struct Node*)malloc (sizeof (struct Node));
	//first line is NULL
	first -> line = NULL;
	for (i = 1; i < n; i++)
	{
		//request space for pointer -> next
		pointer -> next = (struct Node *)malloc(sizeof (struct Node));
		pointer = pointer -> next;
		pointer -> line = NULL;
	}
	pointer -> next = first;
	pointer = first;
	while (fgets (currentline, MAXLEN, fp ) != NULL)
	{
		if (pointer -> line != NULL) //link list full
			free (pointer -> line);
		pointer -> line = (char *) malloc (strlen(currentline) + 1);
		strcpy(pointer -> line, currentline);
		pointer = pointer -> next;
	}
	for (i = 0; i < n; i++)
	{
		if(pointer -> line != NULL)
			printf("%s", pointer -> line );
		pointer = pointer -> next;
	}
	fclose(fp);
	return 0;
}
