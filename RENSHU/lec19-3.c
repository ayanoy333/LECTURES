#include<stdio.h>
#include<stdlib.h>

int main (int argc,char**argv)
{
    int sum = 0;
    for (int i = 1;i <= 100; i++)
    {
        printf("i = %d, ",i);
        sum += i;           //sum = sum + i
        printf("sum = %d\r\n",sum);
    }
    printf("sum = %d\r\n",sum);
    printf("n(n+1)/2 = %d\r\n",100*(100+1)/2);
}