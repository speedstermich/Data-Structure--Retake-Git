#include <stdio.h>
#include <string.h>
#define MAX 100

int main(int argc, char  *argv[]) {

	char number[MAX], last;
	int i = 0, len, j, decimal;

	//strcpy(number, "0.000000000000002");
	scanf("%s", number);
	for(i = 1, j = i -1;  i < strlen(number); i++, ++j)
	{
			last = number[strlen(number) - 1];
			decimal = j;
	}
	if (number[0] <= '0')
	{
		printf("%ce-%d\n", last, decimal - 1);
	}
	if()
	return 0;
}
