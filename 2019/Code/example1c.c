#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {
	int num1, num2, num3;
	char op1, op2, op3;

	num1 = 0;
	op1 = '+';

	while (op1 != '=') //when operator not '='
	{
		scanf("%d %c", &num2, &op2 ); //input put in num2 and op2

		//when op * or /
		while (op2 == '*' || op2 == '/') {
			scanf("%d %c", &num3, &op3 );
			//while (op3 == '*' || op3 == '/')
			//scanf ("%d ")
			if (op2 == '*')
			{
				num2 *= num3;
				//printf("%d\n", num2 );
			}
			else if(op2== '/' )
			{
				num2 /= num3;
				//printf("%d\n",num3 );
				//printf("%d\n",num2 );
			}
			op2 = op3; // op3 operation same as op2
		}

		 //operation + and -
		if(op1 == '+')
                num1 += num2;
            else if(op1 == '-')
                num1 -= num2;
            op1 = op2; //operation 1 and 2 is same
      }

	printf("%d",num1);

	return 0;
}

/**#define MAX 512
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
		//else if (calc[i] == '/' || calc[i + 1] == '/'){
			//calc[i] = atoi(&calc[i - 1]) / atoi(&calc[i + 1]);
			//printf("%d", calc[i]);
		//}
		else{
			continue;
		}

	return 0;
	}
}**/
