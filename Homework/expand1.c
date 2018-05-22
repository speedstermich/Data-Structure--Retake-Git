/* expand,.c*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define MAX 512
void EXPAND (char s1[], char s2[]);

int main(int argc, char const *argv[])
{
	char character[ MAX ], expand[ MAX ];

	gets (character);
	EXPAND ( character, expand );
	puts ( expand );

	return 0;
}

//expand function
void EXPAND (char s1[], char s2[])
{
	char c;
	int i, j;
	i = j = 0;

	//loop for scan input

	while (s1[i] != '\0')
	{
		s2[j++] = s1[i];
	 	if ( s1[ 1 + i ] == '-' && s1[i] < s1[i + 2] )
		{
			for ( c = s1[i] + 1; c <= s1[i + 2]; c++, j++ )
				s2[j] = c;
			i = i + 3;
		}
		else
 			i++;
	}
	//end of  expand
	s2[ j ] = '\0';
}

//function for check is capital or digit or small
/*int isCongener ( char s1[], char s2[] )
{
	if  ( isupper (s1) && isupper (s2) )
		return 1;
	if ( islower (s1[]) && islower (s2[]) )
		return 1;
	if( isdigit (s1[]) && isdigit (s2[]) )
		return 1;
return 0;
}*/
