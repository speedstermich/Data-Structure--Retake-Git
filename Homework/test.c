#include <stdio.h>

int main(int argc, char const *argv[]) {
int arr[] = {19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79};
int i;
for(i = 0; i < 12; i++)
{
	printf("%d %d\n", arr[i], arr[i] %13);
	
}
}
