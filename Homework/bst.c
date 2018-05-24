#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBER 100

struct bst{
	int data;
	struct bst *left;
	struct bst *right;
};
struct bst* newNode(int data);

struct bst* ArrayToBST(int arr[], int start, int end)
{
	if(start > end)
		return NULL;

		int mid = (start + end ) / 2;
		struct bst *root = newNode(arr[mid]);
		root ->left = ArrayToBST(arr, start, mid -1);
		root->right = ArrayToBST(arr, mid +1, end);

		return root;
}

struct bst* newNode(int data)
{
	struct bst* node = (struct bst *)malloc(sizeof(struct bst));
	node->data = data;
	node->left = NULL;
	node -> right = NULL;

	return (node);
}

void preOrder(struct bst* node)
{
	if (node == NULL)
		return;
	printf("%d ", node -> data);
	preOrder(node -> left);
	preOrder(node -> right);
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

	struct bst *root = ArrayToBST(array, 0, number - 1);
	preOrder(root);
	/*for(i = 0; i < number; i++)
	{
		printf("%d ", array[i]);
	}*/
	return 0;
}
