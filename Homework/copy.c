#include <stdio.h>
#include <stdlib.h>
int main()
{
	//open file
	freopen ( "fcopy.in", "r", stdin);
	freopen ("fcopy.out", "w", stdout);
	char input, output;
	input = getchar(); //read word in file

	while (input != EOF) //read untill End Of File
	{
		if ( input == ' ' || input == '\t') //if found space and tab
		{
		 	if( output != ' '  &&  output != '\t')  // if another space or other symbol
			{
				printf(" " );
			}
		}
		else
			printf("%c", input ); //copy input to output
			output = input ;
			input = getchar(); // input get next char
	}
exit (0);
return 0;
}
