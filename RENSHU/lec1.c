#include<stdio.h>
/**
 * @brief int型関数mainはプログラムの最初に呼ばれる特殊な関数
 * argc,argvを引数にとる
 * プロクラムにこれらをセットするにはshellの役目
 * shell　=　実行可能ファイルをメモリーに読み込む
 * 引数などもそのメモリー空間からアクセス可能な場所にセットする
 * @param argc argcには引数の数がセットされる
 * @param argv argvには変数の文字列がセットされる
 * @return int 正常終了時　0　異常終了時は今はない
 */
int main(int argc,char**argv)
{
    printf("Hello World\r\n");  
    return 0;
}