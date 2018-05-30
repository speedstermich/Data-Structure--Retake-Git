#include <stdio.h>

#define MAXWORD 32

struct BSTnode{
	char word[MAXWORD];
	struct BSTnode *right, *left;
};


int main(int argc, char const *argv[]) {
	FILE *fp;

	if((fp = fopen("in.txt", "r")) == NULL)
	{
		fprintf(stderr, "File Doesn't Exist !!\n");
		return -1;
	}

	/*while()
	{

	}*/
	return 0;
}
