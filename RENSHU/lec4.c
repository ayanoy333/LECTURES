#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char**argv)
{
    char input[80];
    int rndnum,inputnum;
Start:
    srand(time(0));
    rndnum = rand()%10;
    printf("0-9までの範囲で乱数を生成しました。\r\n数を当ててください");
Loop:
    printf(">");
    scanf("%s",input);
    inputnum = input[0] - 0x30;
    if (input[0] == 'q')
    {
        printf("終了します\r\n");
        return 0;
    }
    if(inputnum == rndnum)
    {
        printf("正解です！\r\n続けますか？(y/n)\r\n");
        scanf("%s",input);
        if(input[0] == 'y')
        {
            goto Start;
        }
        else
        {
            printf("終了します\r\n");
            return 0;
        }
    }
    if (abs(inputnum - rndnum) < 2)
    {
        printf("おしい！\r\n");
    }
    else if(inputnum > rndnum)
    {
        printf("数が大きいです\r\n");
    }
    else if(inputnum < rndnum)
    {
        printf("数が小さいです\r\n");
    }
    goto Loop;
}