#include<stdio.h>
#include<stdlib.h>

int sub1(int i)
{
    i=10;

    printf("sub1:i = %d\r\n",i);
    return i;
    
}

int sub2(int i)
{
    i=100;
    printf("sub2:i = %d\r\n",i);
    return i;
}


int main(void)
{
        int i=1;
        sub1(i);
        sub2(i);
        printf("%d\r\n",i);
}