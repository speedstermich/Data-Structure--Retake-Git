#include <stdio.h>

#define MAXSIZE 100
void InserList(int array[], int n, int i, int item)
{
	int j;
	if(n  == MAXSIZE || i < 1 || i > n + 1)
		printf("Error Insertion\n");
	for( j = n - 1; j >= i - 1; j-- )
		array[j + 1] = array[j];
	array[i - 1] = item;
	n++;
}

void DeleteList(int array[], int n, int i)
{
	int j;
	if(i < 1 || i > n)
		printf("Error Deletion\n");
	for(j = i; j < n; j++)
		array[j - 1] = array[j];
	n--;
}

int Locate(int array[], int n, int item)
{
	int i;
	for(i = 0; i < n; i++)
		if(array[i] == item)
			return i + 1;
	return -1;
}

void Purge(int array[], int n)
{
	int i = 0, j;
	while(i < n)
	{
		j = i + 1;
		while(j < n)
			if(array[j] == array[i])
				DeleteList(array, n, j + 1);
			else
				j++;
		i++;
	}
}
