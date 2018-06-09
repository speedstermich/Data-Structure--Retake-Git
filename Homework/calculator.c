#include <stdio.h>

struct Stack{
	int number;
	char op;
	struct Stack *next;
};


int main(int argc, char const *argv[]) {
	char op;
	int number;
	while (op != '=')
	{
		//scanf("%d", &number);
		op = getchar();
	}
	return 0;
}
