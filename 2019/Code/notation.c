#include <stdio.h>
#include <string.h>

char num[110];
char result[110];
int len;

int main()
{
    int i,j;
    int s1,s2;                //小数点位置，字符串首个非零数位置
    int find1 = 0;
    int find2 = 0;            //find1:是否找到小数点位置标志位，find2:是否找到首个非零数位置，0：表示未找到
    int index;

    scanf("%s",num);
    len = strlen(num);        //读取字符串长度

    for(i = 0;i < len;++i)   //寻找原字符串中小数点与首个非零数的位置
    {
        if(find1 && find2)
            break;

        if(num[i] == '.'){
            s1 = i;
            find1 = 1;
        }
        else if(num[i] != '0' && !find2){
            find2 = 1;
            s2 = i;
        }
    }

    if(s1-s2 > 0)        //根据二个位置确定指数大小
        index = s1-s2-1;
    else if(s2 > s1)
        index = s1-s2;

    j = 0;
    for(i = s2;i < len;++i)       //确定底数
    {
        if(num[i] == '.')
            continue;
        else if(i == s2) {      //确定底数小数点位置

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
