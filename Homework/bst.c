#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBER 100

struct bst{
	int data;
	struct bst *left;
	struct bst *right;
};

struct bst* newNode(int data)
{
	struct bst* node = (struct bst *)malloc(sizeof(struct bst));
	node->data = data;
	node->left = NULL;
	node -> right = NULL;

	return (node);
}

void sort_array(int arr[], int n)
{
	int i, j, tmp, index;
	for(i = 0; i < n; i++)
	{
		index = i;
		for(j = i; j < n; j++)
			if(arr[index] > arr[j])
				index = j;
		tmp = arr[i];
		arr[i] = arr[index];
		arr[index] = tmp;
	}
}
int main()
{
	int number, array[MAX_NUMBER];
	int i;
	scanf("%d", &number);
	for(i = 0; i < number; i++)
	{
		scanf("%d", &array[i]);
	}
	sort_array(array, number);
	for(i = 0; i < number; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
