#include<stdio.h>
#include<stdlib.h>

int main (int argc,char**argv)
{
    int a;
    a = 10;

    a = a + 1;
    a++;        //a　に　a + 1 を代入
    a += 1;     //a = a + 1と同じ
    ++a;
    a += 2;     //2を足してからaに代入

    int b;

    a = 1;
    b = a++;        //bにaを代入してから a にインクリメント

    printf("a = 1,b = a++ のとき　a = %d, b = %d\r\n",a,b);

    a = 1;
    b = ++a;        //++したあとにbに代入
    printf("a = 1,b = ++a のとき、a = %d, b = %d\r\n",a,b);

}