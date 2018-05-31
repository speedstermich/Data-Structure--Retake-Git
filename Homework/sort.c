#include <stdio.h>

#define MAX 101
int count = 0;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void QuickSort(int k[ ], int left, int right)
{
	int i, last;
	if(left<right)
	{
		last=left;
		for(i=left+1;i<=right;i++)
			if(k[i]<k[left])
				swap(&k[++last], &k[i]);
				//count++;
			swap(&k[left], &k[last]);
		QuickSort(k,left,last-1);
		QuickSort(k,last+1,right);
	}
}

/*void BubbleSort()
{

}

void SelectionSort()
{

}

void MergeSort()
{

}*/

void Adjust(int k[ ], int i, int n)
{
	int j, temp;
	temp = k[i];
	j = 2 * i + 1;
	while(j < n)
    	{
        	if(j < n-1 && k[j]<k[j+1])
			j++;
        	if(temp>=k[j])
			break;
		k[(j-1)/2]=k[j];
		j=2*j+1;
	}
	k[(j-1)/2]=temp;
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
		scanf("%d ", &array[i]);
	}
	if(choose == 1)
	{
		QuickSort(array, 0, number - 1);
		PrintArray(array, 0, number);
		printf("%d", count);
	}
	else if(choose == 2)
	{
		Adjust(array, 0, number - 1);
		PrintArray(array, 0, number);
		printf("%d", count);
	}
	return 0;
}
