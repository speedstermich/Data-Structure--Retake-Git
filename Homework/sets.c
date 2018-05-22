#include <stdio.h>
#define MAX 50

int main()
{
	int A_set[MAX]  = {0} , B_set[MAX] = {0} ;
	int A_size  , B_size;
	int loop_out;
	int i,  j, k;

	loop_out = 0;
	A_size = 0;
	B_size = 0;

	//Input Set A
	while (A_size < MAX && loop_out == 0)
	{
		scanf( "%d", &A_set[A_size]);
		if (A_set[A_size] == -1) //if SET A equal -1 loop out become 1  and out of loop
		loop_out++;
		A_size++;
		//A_set[A_size] = number1;
		//++A_size;
		//if (A_set[ A_size ] = -1)
			//break;
	}
	// Reset loop_out
	loop_out = 0;
	//Input Set B
	while (B_size < MAX && loop_out == 0)
	{
		scanf( "%d", &B_set[B_size]);
		if (B_set[B_size] == -1) //if SET B equal -1 loop out become 1  and out of loop
		loop_out++;
		B_size++;
		//A_set[A_size] = number1;
		//++A_size;
		//if (A_set[ A_size ] = -1)
			//break;
	}

	//checking for the same element
	for (i = 0; i < A_size - 1; i++) //SET A
	{
		for (j = 0, k = 0; j < B_size - 1; j++) //SET B
		{
			if (A_set[i] != B_set[j]) //When set A and B isn't same k++
			k++;	//the same element was stored in k array (temporary)
			if (k == B_size - 1) //
			printf("%d ", A_set[i]);
		}
	}

return 0;
}
