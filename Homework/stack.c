#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Stack{
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity)	//create stack fucntion
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int*) malloc(stack -> capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
	return stack -> top == stack -> capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
	return stack -> top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack -> array[++stack -> top] = item;
}

// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return printf("error ");
    return printf("%d ", stack -> array[stack -> top--]);
    //stack->array[stack->top--];
}

int main(int argc, char const *argv[]) {
	struct Stack* stack = createStack(100);
	int control, number[MAX];
	int i , j, item;
	i =0;

	while(control != -1)
	{
		scanf("%d",&control);
		number[i] = control;
		i++;
	}

	for (j = 0; j < i; j++)
	{
		if (number[j] == 1)
		{
			item = number[j+1];
			push(stack, item);
			continue;
		}
		else if (number[j] == 0)
		{
			pop(stack);
			continue;
		}
	}
	return 0;
}
