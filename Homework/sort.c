#include <stdio.h>

#define MAX 101
int count = 0;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int k[ ], int left, int right)
{
	int i, last;
	if(left<right)
	{
		last=left;
		for(i=left+1;i<=right;i++)
		count++;
			if(k[i]<k[left])
				swap(&k[++last], &k[i]);
			swap(&k[left], &k[last]);
		quickSort(k,left,last-1);
		quickSort(k,last+1,right);
	}
}



void PrintArray(int array[], int start, int end)
{
	int i;
	for(i = start; i < end; i++)
	{
		printf("%d ", array[i]);
	}
printf("\n");
}

int main(int argc, char const *argv[]) {
	int number, choose, i;
	int array[MAX];
	scanf("%d %d", &number, &choose);
	for(i = 0; i < number; i++)
	{
		scanf("%d", &array[i]);
	}
	if(choose == 1)
	{
		quickSort(array, 0, number - 1);
		PrintArray(array, 0, number);
		printf("%d", count);
	}

	return 0;
}
