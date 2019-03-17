#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char num[110];
char result[110];
int len;

int main()
{
    int i,j;
    int decimal,decimal2;                //decimal value position
    int find1 = 0;
    int find2 = 0;            //find1:finding decimal symbol，find2:findong non zero，0：表示未找到
    int index;

    scanf("%s",num);
    len = strlen(num);        //read string lenght

    for(i = 0;i < len; ++i)   //finding non zero and decimal symbol
    {
        if(find1 && find2)
            break;
        if(num[i] == '.'){		//if finding decimal symbol, decimal symbol position = i, finding = 1
            decimal = i;
            find1 = 1;
        }
        else if(num[i] != '0' && !find2){  //if finding non zero, find2 = 1
            find2 = 1;
            decimal2 = i;
        }
    }

    if(decimal - decimal2 > 0)        //from decimal1 and 2 decide index
        index = decimal - decimal2 - 1;
    else if(decimal2 > decimal)
        index = decimal - decimal2;
    j = 0;
    for(i = decimal2; i < len;++i)       //decide decimal
    {
        if(num[i] == '.')
            continue;
        else if(i == decimal2) {      //decide decimal position
            if(num[i+1]){
                result[j++] = num[i];
                result[j++] = '.';
            }
            else
                result[j++] = num[i];
        }
        else
            result[j++] = num[i];
    }
    result[j] = '\0';

    printf("%se%d\n",result,index);
    return 0;
}
