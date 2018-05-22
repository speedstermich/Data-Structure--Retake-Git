#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	FILE *fp1;
	fp = fopen ("fcopy.in", "r");
	fp1 = fopen ("fcopy.out", "w");
	//freopen ("fcopy.in", "r", stdout);
	//freopen ("fcopy.out", "w", stdout);
	char input, output;
	inp = getchar();

	while (input != EOF)
	{
		if ( input == ' ' || input == '\t')
		{
			if (output != ' ' &&  output != '\t')
				printf(" " );
		}
		else
			printf("%c", input );
			output = input ;
			input = getchar();
	}
exit (0);
}
