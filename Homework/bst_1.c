#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

struct BST{
	int key;
	struct BST *left, *right;
};

struct BST *newNode(int item)
{
	struct BST *node = (struct BST *)malloc(sizeof(struct BST));
	node->key = item;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void Print(struct BST *root)
{
	if(!root)
		root;
	if(!root->left && !root->right)
	{
		printf("%d ", root->key);
		return;
	}
	if(root->left)
	{
		Print(root->left);
	}
	if(root->right)
	{
		Print(root->right);
	}
}

struct BST  *InsertNode(struct BST *node, int data)
{
	if(node == NULL)
		return newNode(data);
	if(data < node->key)
		node->left = InsertNode(node->left, data);
	else if(data >= node->key)
		node->right = InsertNode(node->right, data);

	return node;
}

int main(int argc, char const *argv[]) {
	int number, arr[MAXSIZE], temp;
	int i;
	struct BST *root = NULL;
	scanf("%d", &number);

	for (i = 0; i < number;  i++)
	{
		scanf("%d", &arr[i]);
		temp = arr[i];
		if(root == NULL)
			root = InsertNode(root, temp);
		else
			InsertNode(root, temp);
	}
	Print(root);
	return 0;
}
