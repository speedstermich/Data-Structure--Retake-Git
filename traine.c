#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	int static MAXSIZE = 100;
	char alpha[MAXSIZE];
	int c, i = 0;

	while ((c = getchar()) != '\n')
	{
		alpha[i] = c;
		++i;
	}
	printf("%s\n", alpha);

	return 0;
}
