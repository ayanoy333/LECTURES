#include <stdio.h>

typedef struct t_bargraph
{
    char name[80];
    int value;
} bargraph;              //グローバル宣言


    
void dispBar(bargraph*bg)       //bgのアドレスを*で受け取った
{
    for (int i = 0; i < 3; i++)
    {
        printf("%s\t", bg[i].name); //　\tはtabキー　　　ポインターでも配列でもかける　*(bg+i)->name
        for (int j = 0; j < bg[i].value; j++)
        {
            printf("*");
        }
        printf("\r\n");
    }
}

int main(int argc, char **argv)
{
    bargraph bg[3] = {         //ローカル状態
    {"chiba   ", 10},
    {"saitama ", 20},
    {"kanagawa", 30}};
    dispBar(bg);
}