#include <stdlib.h>
#include <stdio.h>

void main(void)
{
    char input[10];
    int i;
    scanf("%s",input);              //%sは文字を意味する
    printf("%02x\r\n",input[0]);    //%02x 2ケタで16進数を表示する
    printf("%d\r\n",input[0]);      //3 x 16 + 5 = 53
    printf("%d\r\n",input[0]-0x30); //-0x30して数字として扱える  1ケタだけの場合使える
    printf("%d\r\n",atoi(input));   //何桁でもatoiは10進数で表せる　alphabet to integer
    scanf("%d",&i);                 //%dなので入力されたものは数値としてiに保存される
    printf("%d\r\n",i);
    sprintf(input,"%d",i);          //文字列同士のprintf　%dでiを表示　その結果をinputに保存
    printf("%s\r\n",input);         //入力されたものが文字列として保存されたことが確認できる (%s)
}