#include<stdio.h>

/**
 * @brief 
 * ファイルから
 * ウィスキーと銘柄と値段を読み取り表示する
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc,char **argv)
{
    struct whiskey
    {
        char name[20];
        int price;
    }whiskey;

FILE *fp;
fp = fopen("lec3.bin","rb");        //read binary
while(fread(&whiskey,sizeof(whiskey),1,fp)>0)   //while文はLoop条件を判断しながらLoopする
{
    printf("%s\t%d\r\n",whiskey.name,whiskey.price);
}
fclose(fp);
return 0;
}