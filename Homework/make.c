#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/*char getWod()
{

}*/

int main(int argc, char const *argv[]) {
	FILE *fp;

	if( (fp = fopen("article.txt","r")) == NULL)
	{
		printf("File Doesn Exist ! \n");
		return -1;
	}

	return 0;
}
