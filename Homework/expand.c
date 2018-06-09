#include <stdio.h>
#include <ctype.h>

#define Max 512

int main(int argc, char const *argv[])
{
	char character[Max] = {'\0'};
	char get;
	int i = 0;

	get = getchar();
	while (get != '\n')
	{
		character [i] = get;
		i++;
		get = getchar();
	}

	for ( i = 0; character[i]; i++ )
	{
		if ( character[i] == '-')
		{
			if (isdigit (character [i - 1]) && isdigit (character [i + 1]) && character[i - 1] <= character[i + 1])
			{
				for (get = character [i -1] + 1; get < character[i + 1]; get++)
					printf("%c", get );
			}
			else if (isupper (character [i - 1]) && isupper (character [i + 1]) && character[i - 1] <= character[i + 1])
			{
				for (get = character [i -1] + 1; get < character[i + 1]; get++)
					printf("%c", get );
			}
			else if (islower (character [i - 1]) && islower (character [i + 1]) && character[i - 1] <= character[i + 1])
			{
				for (get = character [i -1] + 1; get < character[i + 1]; get++)
					printf("%c", get );
			}
			else
			{
				printf("%c", character[i] );
			}
		}
		else
		{
			printf("%c", character[i] );
		}
	}
	printf("\n" );
	return 0;
}
