#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char a[200],b[200],c[200];

//checking in i place want to change
int judge(int i,int l)
{
    int j;
    for(j = 0; j < l; j++)
        if( (c[i + j] != a[j]) &&  (c[i + j] != a[j] + 'a' - 'A') && (c[i + j] != a[j] + 'A' - 'a') )
            return 0;
            return 1;
}
int main()
{
    int l,i, len = 0;
    char ch;
    scanf("%s",a);
    scanf("%s",b);
    l = strlen(a);

    freopen("filein.txt","r",stdin); //open file as input
    freopen("fileout.txt","w",stdout); //open file as output
    memset( c, '\0' ,sizeof(c));

    while(ch != EOF)
    {
        ch  = getchar();
        c[len++] = ch;
    }
    for(i = 0; i < len - 1; i++)
    {
        if( i + l >= len - 1)
            printf("%c",c[i]);
        else
        if( judge ( i, l))
        {
            printf("%s",b);
            i += l - 1;
        }
        else
            printf("%c",c[i]);
    }
exit (0);
return 0;
}
