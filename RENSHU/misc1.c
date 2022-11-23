#include<stdio.h>
#include<stdlib.h>
#include "misc1.h"

void dispMessage(int result)
{
    switch(result)
    {
        case EQUAL:
        printf("正解です\r\n");
        break;
        case BIG:
        printf("数が大きいです\r\n");
        break;
        case SMALL:
        printf("数が小さいです\r\n");
        break;
        case SIMILAR:
        printf("おしい\r\n");
        break;
    }
}
int judge(int inputnum,int rndnum)
{
    int diff = inputnum - rndnum;
    int result = 0;
    if(diff == 0)
    result = EQUAL;
    else if(abs(diff) < 2)
    result = SIMILAR;
    else if(diff< 0)
    result = SMALL;
    else if(diff>0)
    result = BIG;
    return result;

}