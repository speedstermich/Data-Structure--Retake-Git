#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "print_array.h"
#define MAX 101

int main(int argc, char const *argv[]) {
	int number, choose, i;
	int array[MAX];
	scanf("%d %d", &number, &choose);
	for(i = 0; i < number; i++)
	{
		scanf("%d", &array[i]);
	}

	if(choose == 1) //true
	{
		SelectionSort(array, number);
		PrintArray(array, 0, number);
		printf("%d\n", count );
	}
	else if(choose == 2)//true
	{
		BubbleSort(array, number);
		PrintArray(array, 0, number);
		printf("%d\n", count );
	}
	else if(choose == 3)
	{
		HeapSort(array, number);
		PrintArray(array, 0, number);
		printf("%d\n", count);
	}
	else if(choose == 4)
	{
		MergeSort(array, number);
		PrintArray(array, 0, number);
		printf("%d\n", count);
	}
	else if(choose == 5) //True
	{
		QuickSort(array, 0, number - 1);
		PrintArray(array, 0, number);
		printf("%d\n", count);
	}
return 0;
}
