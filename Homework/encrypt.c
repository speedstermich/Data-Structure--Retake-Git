#include <stdio.h>

#define KEY 50
int main(int argc, char *argv[])
{
	char key[KEY];

	FILE *inputfile;
	FILE *outputfile;

	scanf("%s", key );

	inputfile = fopen("encrypt.txt"., "r");
	if (inputfile == NULL)
	{
		printf("FILE DOESN'T EXIST");
		return (1);
	}
	

	return 0;
}
