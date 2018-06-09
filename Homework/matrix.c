#include <stdio.h>
#define N 10

int main()
{
	int n, matrix[N][N], row, collumn, adder;
	char op;

	scanf ( "%d" , &n);

	/*if (n >= 1)
	{
		goto start;
	}
	else
	{
		printf("Out of Range\n");
		return 0;
	}
start: */
	for(row = 0; row < n; row++)
	{
		for (collumn = 0; collumn < n; collumn++)
		scanf( "%d" , &matrix[row][collumn] );
	}

	while( 1 )
	{
		op = getchar();
		op = getchar();

			if ( op == '#' )
			{
		  		for( row = 0; row < n; row++ )
		  		{
			  		for ( collumn = 0;  collumn < n; collumn++ )
			  		printf( "%5d" ,  matrix [row][collumn] );
			  		printf( "\n" );
		  		}
			return 0;
			}

		for(row = 0; row < n;  row++)
		for (collumn = 0; collumn < n; collumn++)
		{
			scanf( "%d", &adder );
			if ( op == '+' )
			{
				matrix[row][collumn] += adder;
			}
			else
			{
				matrix[row][collumn] -= adder;
			}
		}
	}

}
