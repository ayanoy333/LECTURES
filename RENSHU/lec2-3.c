#include<stdio.h>
#include<string.h>

int main(int argc,char**argv)
{
    char str[80];           //文字列char型　80確保
    strcpy(str,"Hello World\r\n");      //strcpy文字列型データのコピー
    printf("%s",str);

    char*a = &str[6];           ///& アドレス演算子
    strcpy(a,"Earth\r\n");
    printf("%s",str);

    return 0;
}