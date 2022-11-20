#include<stdio.h>

/**
 * @brief 
 * test.txtを作成し、nekotyanの8文字を書き込みクローズする
 * @param argc
 * @param argv
 * @return int
 */

int main(int argc,char**argv)
{
    FILE*fp;
    fp = fopen("lec3.bin","wb");
    if(fp != NULL)
    {
        fwrite("nekotyan",sizeof(char),8,fp);
        fclose(fp);
    }
    return 0;
}