#include <stdio.h>

typedef struct t_bargraph
{
    char name[80];
    int value;
} bargraph;

bargraph bg[3] = {        //関数の外にいるのはグローバル状態
    {"chiba   ", 10},
    {"saitama ", 20},
    {"kanagawa", 30}};

void dispBar(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%s\t", bg[i].name); //　\tはtabキー
        for (int j = 0; j < bg[i].value; j++)
        {
            printf("*");
        }
        printf("\r\n");
    }
}

int main(int argc, char **argv)
{
    dispBar();
}