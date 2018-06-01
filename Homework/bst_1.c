#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

struct BST{
	int key;
	struct BST *left, *right;
};

struct BST * newNode(int item)
{
	struct BST *node = (struct BST *)malloc(sizeof(struct BST));
	node->key = item;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int main(int argc, char const *argv[]) {
	int number, arr[MAXSIZE], temp;
	int i;
	scanf("%d", &number);

	for (i = 0; i < number;  i++)
	{
		scanf("%d", &arr[i]);
		temp = arr[i];
		
	}

	return 0;
}
