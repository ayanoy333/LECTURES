#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 25

char glider_gun[HEIGHT][WIDTH] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*'},
    {'*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}}; // /80 x 80 のサイズは確保されているが、初期化したいところだけ書けば良い


char tateyoko[HEIGHT][WIDTH] = {
    {' ','*',' '},
    {' ','*',' '},
    {' ','*',' '},
};

/**
 * @brief
 * ３次元配列で WIDTH x HEIGHT を２面用意する
 * fieledは上下と左右がつながるように一回り大きく用意する
 */
char field[2][HEIGHT + 2][WIDTH + 2];
bool scr; // どちらの面を表示するのかを0，1で表現する

/**
 * @brief
 * dataをfieldへコピーするが一回り違うので＋１した位置へコピーする
 * @param data
 * @return * void
 */
void loadData(char data[][WIDTH])
{
    for (int j = 0; j < HEIGHT; j++)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            if (data[j][i] == '*'){
                field[scr][j + 1][i + 1] = '*';
            }else{
                field[scr][j + 1][i + 1] = ' ';
            }
        }
    }
}

/**
 * @brief
 * 現在のscrではない方のfieldを初期化する
 */
void initNextScreen(void)
{
    for (int j = 0; j < HEIGHT+2; j++)
    {
        for (int i = 0; i < WIDTH+2; i++)
        {
            field[!scr][j][i] = ' ';
        }
    }
}

void prepareScreen4Judge(void)
{
    // 上を下へコピーする
    for (int i = 0; i < WIDTH; i++)
    {
        field[scr][HEIGHT + 1][i + 1] = field[scr][1][i + 1];
    }
    // 下を上へコピーする
    for (int i = 0; i < WIDTH; i++)
    {
        field[scr][0][i + 1] = field[scr][HEIGHT][i + 1];
    }
    // 左を右へコピーする
    for (int j = 0; j < HEIGHT; j++)
    {
        field[scr][j + 1][WIDTH + 1] = field[scr][j + 1][1];
    }
    // 右を左へコピーする
    for (int j = 0; j < HEIGHT; j++)
    {
        field[scr][j + 1][0] = field[scr][j + 1][WIDTH];
    }
    // 四隅を対角へコピー
    field[scr][0][0] = field[scr][HEIGHT][WIDTH];         // 左上は右下からコピー
    field[scr][0][WIDTH + 1] = field[scr][HEIGHT + 1][1]; // 右上は左下からコピー
    field[scr][HEIGHT + 1][0] = field[scr][1][WIDTH];     // 左下は右上からコピー
    field[scr][HEIGHT + 1][WIDTH + 1] = field[scr][1][1]; // 右下は左上からコピー
}

/**
 * @brief
 * 生死判定をおこなう
 * 誕生：死んでいるセルの周囲に 3つの生きているセルがあれば次の世代では生きる（誕生する）
 * 維持：生きているセルの周囲に2つか3つの生きているセルがあれば次の世代でも生き残る
 * 死亡：上以外の場合には次の世代では死ぬ
 */
void dead_or_alive()
{
    initNextScreen();      // 次のスクリーンに今のスクリーンをコピーする
//    prepareScreen4Judge(); // 現在のスクリーンの上下左右をつなげる処理をする
    for (int j = 0; j < HEIGHT; j++)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            // k,l の周囲のセル数を数える
            int k = i + 1;
            int l = j + 1;
            int lifenum =
                (field[scr][l - 1][k - 1] == '*') + (field[scr][l    ][k - 1] == '*') + (field[scr][l + 1][k - 1] == '*') +
                (field[scr][l - 1][k    ] == '*')                                     + (field[scr][l + 1][k    ] == '*') +
                (field[scr][l - 1][k + 1] == '*') + (field[scr][l    ][k + 1] == '*') + (field[scr][l + 1][k + 1] == '*');
            if ((field[scr][l][k] == ' ') && (lifenum == 3))
            {
                // 次のスクリーンにセットする
                field[!scr][l][k] = '*';
            }
            if ((field[scr][l][k] == '*') && ((lifenum == 2) || (lifenum == 3)))
            {
                // 次のスクリーンに生き残りをセットする
                field[!scr][l][k] = '*';
            }
        }
    }
}

void draw(void)
{
    system("clear");
    for (int j = 0; j < HEIGHT; j++)
    {
        printf("%02d:",j+1);
        for (int i = 0; i < WIDTH; i++)
        {
            int k = i + 1;
            int l = j + 1;
            printf("%c", field[scr][l][k]);
        }
        printf("\r\n");
    }
}

void init()
{
    scr = 0;
//    loadData(tateyoko);
    loadData(glider_gun);
}

int main(int argc, char **argv)
{
    init();
    while(1){
        draw();
        dead_or_alive();
        scr = !scr;
        usleep(100*1000);
    }
}