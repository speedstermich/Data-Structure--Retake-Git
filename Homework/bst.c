#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBER 100

struct bst{
	int data;
	struct bst *left;
	struct bst *right;
};
struct bst* newNode(int data);

struct bst* newNode(int data)
{
	struct bst* node = (struct bst *)malloc(sizeof(struct bst));
	node->data = data;
	node->left = NULL;
	node -> right = NULL;

	return node;
}

struct bst* Insert(struct bst* node, int data)
{
	//if tree is empty return a new node
	if(node == NULL)
		return newNode(data);
	//recursion insert to the tree
	if(data < node->data)
		node->left = Insert(node->left, data);
	else if (data > node->data)
		node->right = Insert(node->right, data);

	//return the node pointer
	return node;
}

void Inorder(struct bst *root)
{
	if(root != NULL)
	{
		Inorder(root->left);
		printf("%d \n", root->data );
		Inorder(root->right);
	}
}

int main()
{
	int number, array[MAX_NUMBER], temp;
	int i;
	struct bst *root = NULL;

	scanf("%d", &number);
	for(i = 0; i < number; i++)
	{
		scanf("%d", &array[i]);
		temp = array[i];
		if (root == NULL)
			root = Insert(root, temp);
		else
			Insert(root, temp);
	}

	Inorder(root);
	return 0;
}
