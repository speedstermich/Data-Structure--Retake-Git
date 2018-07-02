#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 82

void Minus(char var1[], char var2[])
{

}

int  judge(char number[], char number2[])
{
	int i;
	int len1 = strlen(number);
	int len2 = strlen(number2);
	if(len1 > len2)
		return 1;
	else
		return 0;

	for(i=0; i < len1; i++)
	 	if(number[i] < number2[i])
	                return 0;
	        return 1;
}

int main(int argc, char const *argv[])
{
	char number[MAX], number2[MAX], transfer[MAX];
	int len1, len2;
	int i;

	fgets(number, MAX, stdin);
	fgets(number2, MAX, stdin);

	if ( judge(number, number2) )
	{
		//minus()
	}


return 0;
}
