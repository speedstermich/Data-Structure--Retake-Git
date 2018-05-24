#include <stdio.h>

#define MAX_NUMBER 100

struct bst{
	int data;
	struct bst *leftChild;
	struct bst *rightChild;
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

	return 0;
}
