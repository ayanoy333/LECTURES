#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum
{
    EQUAL,
    BIG,
    SMALL,
    SIMILAR
};

void dispMessage(int result)
{
    switch (result) //if文の一種
    {
    case EQUAL:
        printf("正解です！\r\n");
        break;
    case BIG:
        printf("数が大きいです\r\n");
        break;
    case SMALL:
        printf("数が小さいです\r\n");
        break;
    case SIMILAR:
        printf("おしい！\r\n");
        break;
    }
}

int judge(int inputnum, int rndnum)
{
    int diff = inputnum - rndnum;
    int result = 0;
    if (diff == 0)
        result = EQUAL;
    else if (abs(diff) < 2)
        result = SIMILAR;
    else if (diff < 0)
        result = SMALL;
    else if (diff > 0)
        result = BIG;
    return result;
}

int main(int argc, char **argv)
{
    char input[80];
    int rndnum, inputnum, diff, result;
    while (1)
    {
        srand(time(0));
        rndnum = rand() % 10;
        printf("0-9までの範囲で乱数を生成しました。\r\n 数を当ててください('q')で終了\r\n");
        while (1)
        {
            printf(">");
            scanf("%s", input);
            inputnum = input[0] - 0x30;
            if (input[0] == 'q')
            {
                printf("終了します\r\n");
                return 0;
            }
            result = judge(inputnum, rndnum);

            dispMessage(result);
            if (result == EQUAL)
            {
                break;
            }
        }
    }
}