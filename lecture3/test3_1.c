#include <stdio.h>

/**
 * @brief
 * test.txtを作成し、aiueoの５文字を書き込みクローズする
 * @param argc
 * @param argv
 * @return int
 */

int main(int argc, char **argv)
{
    FILE *fp;
    fp = fopen("test.bin", "wb");
    if (fp != NULL)
    {
        fwrite("aiueo", sizeof(char), 5, fp);
        fclose(fp);
    }
    return 0;
}