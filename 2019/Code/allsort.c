#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 11

//symbol, array, n as global variabel
int symbol[MAX], array[MAX];
int n;

//full sort func
void allsort(int index){
	int i;
	if (index >= n){
		for(i = 0; i < n; i++){
			printf("%d ", array[i] );
		}
		printf("\n");
		return;
	}
	for(i = 0; i < n; i++){
		if (symbol[i] == 0){
			array[index] = i + 1;
			symbol [i] = 1;
			allsort(index + 1);
			symbol[i] = 0;
		}
	}
}

int main(int argc, char const *argv[]) {
	scanf("%d", &n);
	allsort(0); //start from 0
	return 0;
}
