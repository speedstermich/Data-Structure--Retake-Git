#include<stdio.h>

int main()
{
	int i,j;
		for (i=0; i<3; i++) {
			for (j=4; j>i; j--) {
				printf(" ");
			}
			for (j=0; j<2*i+1; j++) {
				printf("*");
			}
			printf("\n");
		}
		for (i=0; i<4; i++) {
			for (j=4; j>i; j--) {
				printf(" ");
			}
			for (j=0; j<2*i+1; j++) {
				printf("*");
			}
			printf("\n");
		}
		for (i=0; i<5; i++) {
			for (j=4; j>i; j--) {
				printf(" ");
			}
			for (j=0; j<2*i+1; j++) {
				printf("*");
			}
			printf("\n");
		}
		for (i=0; i<5; i++) {
			for (j=0; j<3; j++) {
				printf(" ");
			}
			printf("***");
			printf("\n");
		}
		int count;
		count = 1;
		while (count <= 2)
		{
			printf("**********\n");
			count++;
		}
		printf("\n");



	return 0;
}
