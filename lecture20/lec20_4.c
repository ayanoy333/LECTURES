#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i=-1;
    for (int i=0;i<10;i++){     //for文の中にもう一度int iを宣言しているので6行目のものとは違うi
    }
    printf("%d\r\n", i);        //for文を抜けたので7行目のものの中には干渉できない
}