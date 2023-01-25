#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int x, y;
    printf("y = x * x\r\n");
    for (int i = -5; i <= 5; i++) // for文も代入と比較とインクリメントが行われている（i=-5を最初の一度だけ代入し、処理終端}に達したら i<=5 であることを確認し、OKなら i++ する
    {
        x = i;     // これは普通の数学の数式と同じ
        y = x * x; // こちらも同じ
                    // プログラムに於いては、a = bと書かれたら数式ではなく、代入文です
        printf("(x,y) = (%d,%d)\r\n", x, y);
    }

    printf("a = a * a\r\n");
    for (int i = -5; i <= 5; i++)
    {
        int a;
        a = i;
        a = a * a;
        printf("(i,a) = (%d,%d)\r\n", i, a);
    }

    printf("i と i * i\r\n");
    for (int i = -5; i <= 5; i++)
    {
        printf("(i,i*i) = (%d,%d)\r\n", i, i*i);
    }
    // 業務的にはプログラムは短い方がバグも少ない
    // 一番最後の書き方が一番効率よく、
    // 無駄な代入や計算もしていないので、これが一番良いプログラムであると言える
}