#include <stdio.h>
#include <stdlib.h>
#include "rnd.h"
#include "misc.h"

int main(int argc, char **argv)
{
    char input[80];
    int rndnum, inputnum, diff, result;
    while (1)
    {
        rndnum = getRnd(0, 9);
        printf("0-9までの範囲で乱数を生成しました。\r\n");
        printf("数を当ててください('qで終了')\r\n");
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