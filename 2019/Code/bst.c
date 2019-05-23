#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 100

struct Tree {
  int data;
  struct Tree *left;
  struct Tree *right;
};

struct Tree *NewNode(int data);
int pathlen = 1;

struct Tree *newNode(int data) {
  struct Tree *node = (struct Tree *)malloc(sizeof(struct Tree));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

struct Tree *Insert(struct Tree *node, int data) {
  if (node == NULL)
    return newNode(data);

  if (data < node->data)
    node->left = Insert(node->left, data);
  else
    node->right = Insert(node->right, data);

  return node;
}

// function for print Tree Leaf
void PrintTree(struct Tree *root) {
  if (!root)
    return;
  if (!root->left && !root->right) {
    printf("%d %d ", root->data, pathlen);
    printf("\n");
    return;
  }

  if (root->left) {
    ++pathlen;
    PrintTree(root->left);
  }
  pathlen -= 1;
  if (root->right) {
    ++pathlen;
    PrintTree(root->right);
  }
  pathlen -= 1;
}

int main(int argc, char const *argv[]) {
  int number, array[MAX_NUMBER], temp;
  int i;
  struct Tree *root = NULL;

  scanf("%d", &number);
  for (i = 0; i < number; i++) {
    scanf("%d", &temp);
    // temp = array[i];
    if (root == NULL)
      root = Insert(root, temp);
    else
      Insert(root, temp);
  }

  PrintTree(root);
  return 0;
}
