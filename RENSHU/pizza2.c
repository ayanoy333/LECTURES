// #50 The user to guess a number from 1-5
// output wheather or not the person is correct

#include <stdio.h>   //標準出入力を扱うヘッダーファイル
//#include <stdbool.h> //真偽を判断する
#include <stdlib.h>  //関数randを使うため
#include <time.h>    //時間を扱うためのマクロ,型,関数が定義,宣言される

int main() // void main(void)が正しい
{
    int maxValue = 5;
    srand(time(NULL));                        // UTC　乱数のseedをtimeで変更する
    int randomNumber = rand() % maxValue + 1; //関数randomNumberにsrandで生成された値を代入 剰余+1

    // printf("%d\n",randomNumber);   //%d 出力変換指定子変数の内容を整数で埋め込む decimal(10進数)

    printf("Guess a number 1-%d:", maxValue);
    int input;           // input()で入力した値を取得した時数値は数字（文字列）と扱われれる
    scanf("%d", &input); // scanf 値や文字を入力するときに使う &アドレス演算子 メモリのアドレスを得る

    if (input == randomNumber)
    {
        printf("You win!\n"); // \n改行 \r行頭に戻る
    }
    else //条件式1が偽で2が真だったとき実行
    {
        printf("You don't win TT\n ");
    }
}
