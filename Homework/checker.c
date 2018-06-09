#include <stdio.h>

struct Stack{
	char data;
	struct Stack *next;
};

/*void Error(char bracket, int line, int *expression)
{
	(*e)++;
}*/

void Push(struct Stack** top_ref, int new_data)
{
	struct Stack* node =(struct Stack *)malloc(sizeof(struct Stack));

	if(node == NULL)
	{
		printf("Stack Overflow\n");
		getchar();
		exit(0);
	}

	node -> data = new_data;
	node -> next = (top_ref);
	(*top_ref) = node;
}

int pop(struct Stack **top_ref)
{
		char res;
		struct Stack *top;

		if(*top_ref == NULL)
		{
			printf("without macthing");
		}
}


int Pop
{

}

int main(int argc, char const *argv[]) {
	int character, line;
	FILE *fp;

	if((fp = fopen("example.c", "r")) == NULL)
	{
		fprintf(stderr, "file can't open !\n");
		return -1;
	}

	while((character = fgetc(fp)) != EOF )
	{
		if(character == '\n')
			line++;
		else if (tmp == '"')
		{
			for (;;)
			{
				character = fgetc(fp);
				if(character =='\\')
					character = fgetc(fp);
				else if (character == '"')
					break;
			}
		}
		else if (character == '\'')
		{
			for (;;)
			{
				character = fgetc(fp);
				if (tmp == '\\')
					tmp = fgetc(fp);
				else if (tmp == '\'')
					break;
			}
		}
		else if (character == '/')
            {
			character = fgetc(fp);
			if (character == '/')
			{
				while ((character = fgetc(fp)) != '\n');
				line++;
                }
                else if (character == '*')
                {
                    flag = 0;
                    character = fgetc(fp);
                    for (;;)
                    {
                        if (flag) break;
                        while (character != '*')
                        {
                            character = fgetc(fp);
                            if (character == '\n') line++;
                        }
                        character = fgetc(fp);

				if (character == '/')
					flag = 1;  
                    }
                }
	}
	return 0;
}
