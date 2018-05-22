#include <stdio.h>
#include <stdlib.h>

//symbol, array, n as global variabel
int symbol[7], array[7];
int n;
void allsort(int index);

int main ()
{
	
	scanf ("%d" , &n); //input n
	allsort(0); //start from 0
	return 0;
}

//full sort func
void allsort(int index)
{
	int i;
	if (index >= n)
	{
		for(i = 0; i < n; i++)
		{
			printf("%d ", array[i] );
		}
		printf("\n");

		return;
	}
	for(i = 0; i < n; i++){
		if (symbol[i] == 0)
		{
			array[index] = i + 1;
			symbol [i] = 1;
			allsort(index + 1);
			symbol[i] = 0;
		}
	}
}
