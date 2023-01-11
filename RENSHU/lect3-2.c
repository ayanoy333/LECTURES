#include<stdio.h>

/**
 * @brief 
 * 構造体に銘柄、値段を入れてファイルに保存
 * 
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
        {"Edradour",300},
        {"Macallan",800},
        {"Hibiki",950},
        };
        FILE *fp;
        fp = fopen("lect3.bin","wb");      //write binary
        fwrite(whiskeys,sizeof(whiskeys),1,fp);
        fclose(fp);
        return 0;
    }
