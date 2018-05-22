//example1a.c

#include <stdio.h>

int main()
{
	int n;
	double e, prime, factor, PI, result;
	n = 1;
	prime = factor = PI = 1;
	result = 0;

	scanf( "%lf", &e );

	while ( result >= e / 2 || n < 2 )
	{
		n++;
		prime = prime * ( 2 * n - 1 );
		factor = factor * ( n - 1 );
		result = factor / prime;
		PI = PI + result;
	}

	printf( "%d %.7lf\n", n, PI*2 );
return 0;
}
