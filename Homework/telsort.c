#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15
#define MAXSIZE 50

struct Contact{
	char name[MAX]	;
	char number[MAX];
};

void ByName(struct Contact list[], int n)
{
	int i, j;
	struct Contact tmp;
	for(i = 0; i < n; i++)
	{
		for(j = i +1; j < n; j++)
		{
			if( strcmp( list[i].name, list[j].name ) > 0)
			{
				//fflush(stdin);
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
				//fflush(stdin);
			}
			//printf("%10s %10s\n", list[i].name, list[i].number);
		}
	}
}

int main(int argc, char const *argv[]) {
	int total, i;
	struct Contact list[MAXSIZE];

	scanf("%d", &total);
	if(total <= MAXSIZE)
	{
		for(i = 0; i < total; i++)
		{
			scanf("%s %s", list[i].name, list[i].number);
			fflush(stdin);
		}
		//fflush(stdin);
		ByName(list, total);
		//fflush(stdin);

		for(i = 0; i < total; i++)
		{
			//fflush(stdin);
			//change to 12
			printf("%12s %12s\n", list[i].name, list[i].number);
		}
	}
	return 0;
}
