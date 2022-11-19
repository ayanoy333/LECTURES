#include <stdio.h>
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int div(int a, int b)
{
    return a / b;
}
void numbers(int i,int j,int k,int l)    //何も返さないvoid
{
    printf("%d %d %d %d\r\n",i,j,k,l);
}
void twotimes(int *i,int *j)    //アドレスをポインターで受け取る
{             //ポインターの実体にアクセスするときは*が必要
    *i *= 2;    //a*=2 と a = a*2 は同じ 呼び出し元の変数と同じアドレスを指せる
    *j *= 2;
}
int main(int argc, char **argv)
{
    int i, j;
    i = 20,j = 10;
    printf("%d\r\n", add(i, j));
    printf("%d\r\n", sub(i, j));
    printf("%d\r\n", mul(i, j));
    printf("%d\r\n", div(i, j));
    numbers(1,2,3,4);
    twotimes(&i,&j);         //i、、jのアドレスを渡す
    printf("%d,%d\r\n",i,j);
    printf("%d\r\n", add(i, j));
    printf("%d\r\n", sub(i, j));
    printf("%d\r\n", mul(i, j));
    printf("%d\r\n", div(i, j));
}