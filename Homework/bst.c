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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
	quickSort(array, 0, number - 1);

	struct bst *root = ArrayToBST(array, 0, number - 1);
	preOrder(root);
	//for(i = 0; i < number; i++)
	//{
	//	printf("%d ", array[i]);
	//}
	return 0;
}
