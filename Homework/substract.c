#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 82

int main(int argc, char const *argv[])
{
	char number[MAX], number2[MAX], transfer[MAX];
	int len1, len2;
	int i;

	fgets(number, MAX, stdin);
	fgets(number2, MAX, stdin);

	len1 = strlen(number);
	len2 = strlen(number2);

	if(len1 > len2)
	{
		for(i = 0; i < len1; i++)
		{

		}
	}
return 0;
}
