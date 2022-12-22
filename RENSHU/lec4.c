#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char**argv)
{
    char input[80];           //メモリの確保?
    int rndnum,inputnum;      //変数(整数値)の宣言
Start:
    srand(time(0));        //乱数生成(引数seed) time()POSIX時間からの経過時間を返す(エポック秒)
    rndnum = rand()%10;    //% 剰余を示す　ここでは10で割った余り
    printf("0-9までの範囲で乱数を生成しました。\r\n数を当ててください");
Loop:
    printf(">");
    scanf("%s",input);
    inputnum = input[0] - 0x30;         //inputした値が文字列なので-0ｘ30して数値化する
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
    if (abs(inputnum - rndnum) < 2)         //abs 絶対値をとる 0か1じゃなければ38行目は実行されない
    {
        printf("おしい！\r\n");
    }
    else if(inputnum > rndnum)              //36行目の条件に当てはまらなかったら
    {
        printf("数が大きいです\r\n");
    }
    else if(inputnum < rndnum)              //36,40行目の条件に合致しなかったらこの条件を判定する
    {
        printf("数が小さいです\r\n");
    }
    goto Loop;                  //当たったらここまで来ない　当たってないからLoopに飛ぶ
}