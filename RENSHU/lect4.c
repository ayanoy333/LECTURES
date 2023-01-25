#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc,char**argv)
{
    char input[80];
    int rndnum,inputnum;

Start:
    srand(time(0));
    rndnum = rand()%10;
    printf("0-9までの数字で乱数を生成しました\r\n数を当ててください");
Loop:
    printf(">");
    scanf("%s",input);                   //キーボードからの入力を書式に従って変数に読み込む
    inputnum = input[0] - 0x30;         //inputした値を-0x30して数値化
    if(input[0] == 'q')
    {
        printf("終了します\r\n");
        return 0;
    }  
    if (inputnum == rndnum)
    {
        printf("正解です!\r\n続けますか?(y/n)\r\n");
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
    if (abs(inputnum - rndnum) < 2)     //絶対値を求めたい変数をabs関数に引数として与える
    {
        printf("おしい!\r\n");
    }
    else if (inputnum > rndnum)
    {
        printf("数が大きいです\r\n");
    }
    else if(inputnum < rndnum)
    {
        printf("数が小さいです\r\n");
    }
    goto Loop;
}

