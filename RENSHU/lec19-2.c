#include<stdio.h>
#include<stdlib.h>

int main(int argc,char**argv)
{
    int x,y;
    printf("y = x * x\r\n");
    for (int i = -5; i<= 5; i++)
    {
        x = i;
        y = x * x;
        printf("(x,y) = (%d,%d)\r\n",x,y);
    }

    printf("a = a * a\r\n");
    for (int i = -5; i <= 5; i++)
    {
        int a;
        a = i;
        a = a * a;
        printf("(i,a) = (%d,%d)\r\n",i,a);
    }

    printf("i と i * i\r\n");
    for (int i = -5; i <= 5; i++)
    {
        printf("(i,i*i) = (%d,%d)\r\n",i,i*i);
    }
}