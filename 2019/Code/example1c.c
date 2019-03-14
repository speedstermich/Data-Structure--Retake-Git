#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 512
int main(int argc, char const *argv[]) {
	int i, j = 0;
	char calc[MAX] = {'\0'};
	//int result[MAX];

	gets(calc);
	//remove whitespace
	for (i = 0; calc[i]; i++) {
		if (calc[i] != ' ') {
			calc[j] = calc[i];
			j++;
		}
	}
	calc[j] = '\0';
	j = 0;
	for (i = 0; calc[i] != '='; i++) {
		if(calc[i] == '*' || calc[i] == '/'){
			if (calc[i] == '*') {
				calc[i] = atoi(&calc[i - 1]) * atoi(&calc[i + 1]);
				printf("%d", calc[i]);
			}
			else if (calc[i] == '/') {
					calc[i] = atoi(&calc[i - 1]) / atoi(&calc[i + 1]);
					printf("%d", calc[i]);
			}
			//if(calc[i] == '+' || calc[i])
			//printf("%d", calc[i]);
			if(calc[i] == '+'){
				calc[i - 1] += atoi(&calc[i+1]);
				printf("%d", calc[i]);
			}
		}
		/*else if (calc[i] == '/' || calc[i + 1] == '/'){
			calc[i] = atoi(&calc[i - 1]) / atoi(&calc[i + 1]);
			//printf("%d", calc[i]);
		}*/
		else{
			continue;
		}

	return 0;
	}
}
