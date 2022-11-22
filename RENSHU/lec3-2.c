#include<stdio.h>

/**
 * @brief 
 * 構造体にウイスキー銘柄と値段を入れて
 * ファイルに保存する
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc,char**argv)
{
    struct whiskey
    {
        char name[20];
        int price;
    };
    struct whiskey whiskeys[3] = {
        {"Jack Daniel",180},
        {"Black Nikka",300},
        {"Talisker",450},
    };
    FILE *fp;
    fp = fopen("lec3.bin","wb");
    fwrite(whiskeys,sizeof(whiskeys),1,fp);
    fclose(fp);
    return 0;
      
}