#include<stdlib.h>
#include<stdio.h>

void main(void)
{
    char input[10];
    int i;
    scanf("%s",input);
    printf("%02x\r\n",input[0]);
    printf("%d\r\n",input[0]);
    printf("%d\r\n",input[0]-0x30);
    printf("%d\r\n"atoi(input));
    scanf("%d",&i);
    printf("")
}