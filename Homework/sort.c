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

}*/

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void merge(int x[ ],int tmp[ ],int left,int leftend,int rightend)
{
	int i=left, j=leftend+1, q=left;

	while(i<=leftend && j<=rightend)
	{
		if(x[i]<=x[j])
			tmp[q++]=x[i++];
		else
			tmp[q++]=x[j++];
	}
	while(i<=leftend)
		tmp[q++]=x[i++];
	while(j<=rightend)
		tmp[q++]=x[j++];
	for(i=left; i<=rightend; i++)
		x[i]=tmp[i];
}

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
		k[(j-1)/	2]=k[j];
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
