#include<stdio.h>

int main(int argc,char**argv)
{
    printf("argc=%d\r\n",argc);
    for(int i = 0; i < argc; i++)
    {
        printf("argv[%d]=%s\r\n",i,argv[i]);
    }
    return 0;
}