#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 512
int result[MAX];

int judge (char number1[], char number2[]){
	int i;
	//判断是否整数1大于或小于整数2
	if(strlen(number1) < strlen(number2)){
		return 0;
	}
	else if(strlen(number1) > strlen(number2)){
		return 1;
	}
	for(i = 0; i < strlen(number1); i++){
		if(number1[i] < number2[i]){
			return 0;
		}
	}
	return 1;
}
/*
function for swap
*/
void swap(char number[], int i, int k){
	char tmp;
	tmp = number[i];
	number[i] = number[k];
	number[k] = tmp;
}
/*
function for substract number 1 and number 2
*/
void minus(char number1[], char number2[], int k1, int k2){
	int i;
	//char k;
	for (i = 0; i < k1; i++, k1--){
		swap(number1, i, k1);
		/*k = number1[i];
		number1[i] = number1[k1];
		number1[k1] = k;*/
	}
	for(i = 0; i < k2; i++, k2--){
		swap(number2, i, k2);
		/*k = number2[i];
		number2[i] = number2[k2];
		number2[k2] = k;*/
	}
	for(i = 0; i < strlen(number1); i++){
		if(i >= strlen(number2)){
			result[i] = number1[i] - '0';
		}
		else{
			result[i] = number1[i] - number2[i];
		}
	}
	for(i = 0; i < strlen(number1); i++){
		while(result[i] < 0){
			result[i] += 10;
			result[i + 1] -= 1;
		}
	}
}

int main(int argc, char const *argv[]) {
	int i, j, k1, k2;
	char number1[MAX], number2[MAX];
	gets(number1);
	gets(number2);
	k1 = strlen(number1) - 1; //为了保证真正的长度
	k2 = strlen(number2) - 1;
	if(judge(number1, number2)){
		minus(number1, number2, k1, k2);
	}
	else{
		printf("-");
		minus(number2, number1, k2, k1);
	}
	i = 512;
	while(result[i] == 0 && i != 0){ //To remove zero array
		i --;
	}
	for(j = i; j >= 0; j--){	//print out result
		printf("%d", result[j]);
	}
	return 0;
}
