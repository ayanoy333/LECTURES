#include <stdio.h>

/**
 * brief
 * ファイルから
 * ウィスキー銘柄と値段を読み取り表示する
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char **argv)
{
    struct whiskey
    {
        char name[20];
        int price;
    } whiskey;

    FILE *fp;
    fp = fopen("test3.bin", "rb");
    while (fread(&whiskey, sizeof(whiskey), 1, fp) > 0)
    {
        printf("%s\t%d\r\n", whiskey.name, whiskey.price);
    }
    fclose(fp);
    return 0;
}