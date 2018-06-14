#include <stdio.h>
#include <stdlib.h>

void print_Path(int path[])
{
	int i = 0;
	while(path [i + 1] != 0)
		printf("%d ", path[i++]);
	printf("%d\n", path[i]);
}
