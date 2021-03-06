#include <stdio.h>
#include <stdlib.h>

int count = 0;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
   //++count;
}
//choose #1
void SelectionSort(int arr[], int n)
{
	int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    	for (i = 0; i < n-1; i++)
    	{
        // Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		{
			++count;
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
	// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}
//choose #2
void BubbleSort(int arr[], int n)
{
	int i, j, flag = 1;
	for(i = n -1; i > 0 && flag == 1; i--)
	{
		flag = 0;
		for(j = 0; j < i; j++)
		{
			++count;
			if( arr[j] > arr[ j +1 ] )
			{
				swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
	}
}
//choose #3
void Adjust(int k[ ], int i, int n)
{
	int j, temp;
	temp = k[i];
	j = 2 * i + 1;
	while(j < n)
    	{
        	if(j < n-1 && k[j] < k[j + 1])
			j++;
		++count;
		if(temp >= k[j])
			break;
		k[ (j - 1) / 2 ] = k[j];
		j = 2 * j + 1;
	}
	k[( j - 1 ) / 2 ] = temp;
}

void HeapSort(int K[], int n)
{
	int i;
	//int temp;
	for( i = n / 2 - 1; i >= 0; i--)
		Adjust(K, i, n );
	for(i = n - 1; i >= 1; i--)
	{
		swap(&K[0], &K[i]);
		Adjust(K, 0, i);
	}
}
//choose #4
void Merge(int x[ ], int tmp[ ], int left, int leftend, int rightend)
{
	int i = left, j = leftend + 1, q = left;

	while(i <= leftend && j <= rightend)
	{
		++count;
		if(x[i] <= x[j])
			tmp[q++] = x[i++];
		else
			tmp[q++] = x[j++];
	}
	while(i <= leftend)
		tmp[q++] = x[i++];
	while(j <= rightend)
		tmp[q++] = x[j++];
	for(i = left; i <= rightend; i++)
		x[i] = tmp[i];
}

void mSort(int k[], int tmp[], int left, int right)
{
	int center;
	if(left < right)
	{
		center = (left + right) / 2;
		mSort(k, tmp, left, center);
		mSort(k, tmp, center + 1, right);
		Merge(k, tmp, left, center, right);
	}
}

void MergeSort(int k[], int n)
{
	int *tmp;
	tmp = (int *)malloc(sizeof (int) *n);
	if(tmp != NULL)
	{
		mSort(k, tmp, 0, n-1);
		free(tmp);
	}
	else
		printf("No Space Left !!");
}

//choose #5
void QuickSort(int k[ ], int left, int right)
{
	int i, last;
	if(left < right)
	{
		last = left;
		for(i = left + 1; i <= right; i++)
		{
			++count;
			if(k[i] < k[left])
				swap(&k[++last], &k[i]);
			//++count;
		}
		swap(&k[left], &k[last]);
		QuickSort(k, left, last-1);
		QuickSort(k, last+1, right);
	}
}
