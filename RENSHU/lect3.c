#include<stdio.h>

/**
 * @brief 
 * tset2.txtを作成し、inuchanの7文字を書き込みクローズ
 * @param argc
 * @param argv
 * @return int
 */

int main (int argc,char**argv)
{
    FILE*fp;
    fp = fopen("inuchan.bin","wb");
    if (fp != NULL)
    {
        fwrite("inuchan",sizeof(char),7,fp);    //sizeof括弧でくくった型指定子を与えるとその大きさをバイト単位で返す
        fclose(fp);
    }
    return 0;
}