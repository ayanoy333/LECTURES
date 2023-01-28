#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int a;  // 変数の宣言
    a = 10; // 代入

    a = a + 1; // 代入（足し算した結果を代入）10 = 10 + 1 ではなく a ← a+1 を代入 a← 10 + 1 を代入するので、aにa+1の結果をう上書きする事になり、結果的に a = 11 になる
    a++;       // 　aのインクリメント a = a + 1 と同じ
    a += 1;    // これも            a = a + 1 と同じ
               // a = a + 1, a++, a += 1 は全部同じです
    ++a;       // a++と同じですが、左辺があるときは結果が変わる
    a += 2;    //  a = a + 2 と一緒   aに2を足してからaに代入する

    int b;

    a = 1;
    b = a++;        //b=aをしたあとにaを++
    printf("a = 1, b = a++ の時、a = %d, b = %d\r\n", a, b);

    a = 1;
    b = ++a;        //bにはaを++した結果を代入する
    printf("a = 1, b = ++a の時、a = %d, b = %d\r\n", a, b);
    // b = a++とb = ++aはaのインクリメントと、bへの代入が行われるが、
    // そのタイミングは異なる。
    // b = a++の時は、先にb = a,続いてa++が行われる
    // b = ++aの時は、先に++aが行われ、続いてb = aが行われる
    // 混乱することが多いので、分けて書く方が良いかもしれません
    // 以下の書き方だと、結果は a = 2,b = 2 になる
    // a = 1;
    // a++;
    // b = a;
}