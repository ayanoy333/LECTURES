#include<stdio.h>
#include<stdlib.h>

int main (void)
{
    int i;
    for (i=0;i<10;i++){     //0-9まではtrue,10<10になるとfalseなのでループを抜ける
    }
    printf("%d\r\n", i);    //10<10になったとき　iは10なので　10が表示される
}