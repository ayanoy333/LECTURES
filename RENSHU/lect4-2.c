#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum
{
    EQUAL,BIG,SMALL,SIMILAR
};
void dispMessage(int result)
{
    switch(result)      //変数の値で処理を分岐させる 変数と数値の一致判定
    {
        case EQUAL:
            printf("正解です！\r\n");
            break;
        case BIG:
            printf("数が大きいです\r\n");
            break;
        case SMALL:
            printf("数が小さいです\r\n");
            break;
        case SIMILAR:
            printf("おしい！\r\n");
            break;
    }
}
int main(int argc,char**argv)
{
    char input[80];
    int rndnum,inputnum,diff,result;
    while (1)
    {
        srand(time(0));
        rndnum = rand() %10;
        printf("0-9までの範囲で乱数を生成しました。\r\n数を当ててください(q)で終了\r\n");
        while(1)
        {
            printf(">");
            scanf("%s",input);
            inputnum = input[0] - 0x30;
            if (input[0] == 'q')
            {
                printf("終了します\r\n");
                return 0;
            }
            diff = inputnum - rndnum;
            if (diff == 0 )
                result = EQUAL;
            else if (abs(diff)<2)
                result = SIMILAR;
            else if (diff < 0)
                result = SMALL;
            else
        
            {
                break;
            }
            
        }
    }
}