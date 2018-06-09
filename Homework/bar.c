#include <stdio.h>

int main(int argc, char const *argv[])
{
	char input, star[50][26];
	int i, j, store[26], index, line;

	for (i = 0; i < 26; i++)
	{
		store[i] = 0;
	}

	input = getchar();
	while (input != EOF) // input untill End Of fFile
	{
		if( ( 'a' <= input ) && (input <= 'z' ) )
		{
			index = input - 'a';
			store[index] = store[index] + 1;
		}
	input = getchar();
	}

	line = 0;
		for ( i = 0; i < 26; i++ )
		{
			if (line < store[i])
			line = store[i];
		}

		for(i = 0; i < line; i++) //convert to *
		{
			for( j = 0; j < 26; j++)
			{
				if (store[j] > 0)
				{
					star[i][j] = '*';
					store[j] = store[j] - 1;
				}
				else
					star[i][j] = ' ';
			}
		}

		//print *
		for (i = line -1; i >= 0; i--)
		{
			for ( j = 0; j < 26; j++)
			{
				printf ("%c", star[i][j] );
			}
			printf("\n" );
		}
 	printf("abcdefghijklmnopqrstuvwxyz");

return 0;
}
