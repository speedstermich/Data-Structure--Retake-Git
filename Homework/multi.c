#include <stdio.h>
#include <stdlib.h>

struct Node {
	int coe; //系数
	int pwr; //幂数
	struct Node *next;
};

void multi (struct Node *poly1, struct Node *poly2, struct Node *temp);

int main(int argc, char const *argv[]) {
	int coef, power, result;
	char c; //c2;
	//int coef2, power2;
	struct Node *head, *p, *q, *p0;
	head = p = NULL;

	do{
		scanf("%d%d%c", &coef, &power, &c); // input the first polynom
		if (head == NULL)
			head = p = (struct Node *)malloc (sizeof (struct Node));
		else
		{
			p -> next = (struct Node *)malloc(sizeof(struct Node));
			p = p -> next;
		}
		p -> coe = coef;
		p -> pwr = power;
		p -> next = NULL;
	}while (c != '\n');

	do{
		scanf("%d%d%c", &coef, &power, &c); //input second polynom
		q == (struct Node *)malloc(sizeof(struct Node));
		q -> coe = coef;
		q -> pwr = power;
		q -> next = NULL;

		// how to multiply polynominal
		for(p = head; p != NULL; p0 = p, p = p -> next)
		{
			if (q -> pwr > p -> pwr)
			{
				if(p == head)
				{
					q -> next = head;
					head = q;
					break;				//put to head
				}
				else
				{
					q -> next = p;
					p0 -> next = q;
					break;				//q pput to before p
				}
			}
			else if(q -> pwr == p -> pwr)
			{
				p -> coe += q -> coe;
				break;
			}
			result -> coe = (p -> coe) * (q -> coe);
			result -> pwr = (p -> pwr) + (q -> pwr);

			if(p == NULL)
				p0 -> next = q;
		}
	}while (c != '\n');



	for (p = head; p != NULL; p = p-> next)
		printf("%d %d ", p -> coe, p -> pwr);
	return 0;
}

void multi (struct Node *poly1, struct Node *poly2, struct Node *temp)
{

}
