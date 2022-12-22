#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum        //列挙型 複数の変数に一連の整数値を付ける
{
    EQUAL,
    BIG,
    SMALL,
    SIMILAR
};
void dipMessage(int result)     
{
    switch (result)
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
int main(int argc, char **argv)
{
    char input[80];
    int rndnum, inputnum, diff, resulut;
    while (1)                           //while(1)　無限ループ
    {
        srand(time(0));
        rndnum = rand() % 10;
        printf("0-9までの範囲で乱数を生成しました。\r\n数を当ててください('q')で終了\r\n");
        while (1)
        {
            printf(">");
            scanf("%s", input);
            inputnum = input[0] - 0x30;
            if (input[0] == 'q')
            {
                printf("終了します\r\n");
                return 0;
            }
            diff = inputnum - rndnum;
            if (diff == 0)
                resulut = EQUAL;
            else if (abs(diff) < 2)     //abs 絶対値
                resulut = SIMILAR;
            else if (diff < 0)
                resulut = SMALL;
            else if (diff > 0)
                resulut = BIG;
            dipMessage(resulut);
            if (resulut == EQUAL)
            {
                break;
            }
        }
    }
}