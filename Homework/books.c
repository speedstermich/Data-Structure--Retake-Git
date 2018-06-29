#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 100
#define MAX_BOOK 500
typedef struct  Books{
	char name[100];
	char author[20];
	char publisher[30];
	char date[10];
}books;
struct Books SaveToStruct(char *s);

void InsertBooks()
{

}

void print(struct Books* arr, int size);

int main(int argc, char const *argv[])
{
 	books book[MAX_BOOK];
	char buffer[BUF_SIZE], input[MAX_BOOK];
	char control;
	int flag, len;

	flag = 0;

	FILE *inputfile;
	FILE *ouputfile;

	inputfile = fopen("book.txt","r");
	if (inputfile == NULL)
	{
		printf("File doesn't exist");
		return -1;
	}
	while (fgets(buffer, BUF_SIZE, inputfile)!=NULL)
	{
		book[flag] = SaveToStruct(buffer);
		flag++;
	}
	//print(book, 10);
	while ((control = getchar()) != '0')
	{
		//control = getchar();
		if (control == '1')
		{
			//while (input != '\n')
			//{
				//fgets(input);
				strcpy(buffer, input);

				book[flag] = SaveToStruct(buffer);

			//}
			//continue;
		}
		else if (control == '2')
		{
			print(book, flag);
			/*scanf("%s", &input[MAX_BOOK]);
			len = strlen(input);*/

			//Search();
			//continue;
		}
		else if(control == '3' )
		{
			scanf("%s",&input[MAX_BOOK]);
			//Delete();
			//continue;
		}
		/*else if (control == '0')
			break;*/

	}
	//print(book, flag);
	//printf("%d\n",len );
	printf("%s\n",book[flag].name );
	return 0;
}

struct Books SaveToStruct(char *s)
{
		books res;
		int flag = 0;
		char *token = strtok(s, " ");
		while(token != NULL)
		{
			if (0 == flag)
            		strcpy(res.name, token);
        		else if (1 == flag)
            		strcpy(res.author, token);
        		else  if (2 == flag)
            		strcpy(res.publisher, token);
			else if (3 == flag)
				strcpy(res.date, token);
        flag++;
        token = strtok( NULL, " " );
    		}
    return res;
}


//void search(char *str)

void print(struct Books *arr, int size)
{
	int i ;
	for (i = 0; i < size; i++)
	{
		printf("%s %s %s %s\n",arr[i].name, arr[i].author, arr[i].publisher, arr[i].date );
	}
}
