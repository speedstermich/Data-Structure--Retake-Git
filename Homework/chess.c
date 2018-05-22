#include <stdio.h>

#define Max 19
int main(int argc, char const *argv[]) {
		int board[Max][Max];
		int chess;
		int i, j;

		for ( i = 0;  i < Max; i++ )
		{
			for ( j = 0; j < Max; j++) {
				scanf("%d ", &board[i][j] );
			}
		}

		printf("this output\n" );
		for ( i = 0;  i < Max; i++ )
		{
			for ( j = 0; j < Max; j++) {
				printf("%d ", board[i][j] );
			}
			printf("\n" );
		}
	return 0;
}
