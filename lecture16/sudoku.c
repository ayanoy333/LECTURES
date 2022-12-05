#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

typedef unsigned short WORD;
int data[9][9];
WORD flag[9][9];

/**
 * @brief フラグのセットをする
 *
 * @param x 0-8
 * @param y 0-8
 * @param val 1-9
 */
void setFlag(int x, int y, int val)
{
#ifdef DEBUG
    printf("(%d,%d) = %d\r\n", x + 1, y + 1, val);
#endif
    int bit = 1 << (val - 1);
    // xy方向のフラグをセット
    for (int i = 0; i < 9; i++)
    {
        flag[i][y] |= bit;
        flag[x][i] |= bit;
    }
    // x,y が各々 0-2, 3-5,6-8 の どの範囲かを特定する
    int ox = x / 3 * 3;
    int oy = y / 3 * 3;
    // ox,oyを左上として、3x3の範囲のフラグを立てる
    flag[ox][oy] |= bit;
    flag[ox][oy + 1] |= bit;
    flag[ox][oy + 2] |= bit;
    flag[ox + 1][oy] |= bit;
    flag[ox + 1][oy + 1] |= bit;
    flag[ox + 1][oy + 2] |= bit;
    flag[ox + 2][oy] |= bit;
    flag[ox + 2][oy + 1] |= bit;
    flag[ox + 2][oy + 2] |= bit;
}

void printBit(void)
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            // 表示は9ビット分でいい
            for (int k = 0; k < 9; k++)
            {
                flag[x][y] & 1 << (8 - k) ? printf("1") : printf("0");
            }
            if (x == 2 || x == 5)
            {
                printf("|");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\r\n");
        if (y == 2 || y == 5)
        {
            printf("-----------------------------+-----------------------------+-----------------------------\r\n");
        }
    }
}

void printData(void)
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            printf("%d", data[x][y]);
            if (x == 2 || x == 5)
            {
                printf("|");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\r\n");
        if (y == 2 || y == 5)
        {
            printf("-----+-----+-----\r\n");
        }
    }
}

int readData(char *filename)
{
    char buff[1024];
    size_t size = 9 + 2;
    char *b = buff;
    FILE *fp;
    fp = fopen(filename, "rt");
    if (fp == NULL)
    {
        printf("file not found %s\r\n", filename);
        return -1;
    }
    int readCount;
    for (int y = 0; y < 9; y++)
    {
        readCount = getline(&b, &size, fp);
        for (int x = 0; x < 9; x++)
        {
            data[x][y] = buff[x] - 0x30;
        }
    }
#ifdef DEBUG
    printf("リードしたデータを表示\r\n");
    printData();
#endif
    return 0;
}

void setVHFlag(void)
{
    // 数字が0以外であれば、縦横のビットを立てる
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (data[x][y] != 0)
            {
                WORD bit = 1 << (data[x][y] - 1);
                for (int k = 0; k < 9; k++)
                {
                    flag[k][y] |= bit;
                    flag[x][k] |= bit;
                }
            }
        }
    }
}

/**
 * @brief 仮置き用フラグのセットをする
 * x,yの3x3領域以外の垂直方向のフラグを立てる
 * ただし、他の領域でもこれから建てようとしたフラグが入りうる場合は
 * フラグのセットをしない
 * @param x
 * @param y
 * @param val
 */
void setVFlagWithoutRange(int x, int y, int val)
{
#ifdef DEBUG
    printf("仮置き垂直方向(x,y,val) = (%d,%d,%d)\r\n", x + 1, y + 1, val);
#endif
    WORD bit = 1 << (val - 1);
    int ignoreVFrom = y / 3 * 3;
    int ignoreVTo = ignoreVFrom + 3;

    for (int v = 0; v < 9; v++)
    {
        if (v < ignoreVFrom || v >= ignoreVTo)
        {
            flag[x][v] |= bit;
        }
    }
}

/**
 * @brief 仮置き用のフラグをセットする
 * x,yの3x3領域以外の水平方向のフラグを立てる
 * ただし、他の領域でもこれから建てようとしたフラグが入りうる場合は
 * フラグのセットをしない
 * @param x
 * @param y
 * @param val
 * @return * void
 */
void setHFlagWithoutRange(int x, int y, int val)
{
#ifdef DEBUG
    printf("仮置き水平方向(x,y,val) = (%d,%d,%d)\r\n", x + 1, y + 1, val);
#endif

    WORD bit = 1 << (val - 1);
    int ignoreHFrom = x / 3 * 3;
    int ignoreHTo = ignoreHFrom + 3;

    for (int h = 0; h < 9; h++)
    {
        if (h < ignoreHFrom || h >= ignoreHTo)
        {
            flag[h][y] |= bit;
        }
    }
}
void setSquareFlag(void)
{
    for (int y = 0; y < 9; y += 3)
    {
        for (int x = 0; x < 9; x += 3)
        {
            for (int yy = 0; yy < 3; yy++)
            {
                for (int xx = 0; xx < 3; xx++)
                {
                    int xxx = x + xx;
                    int yyy = y + yy;
                    if (data[xxx][yyy] != 0)
                    {
                        // 左上がi,jなので、そこから３ｘ３の範囲のビットを立てる
                        WORD bit = 1 << (data[xxx][yyy] - 1);
                        flag[x][y] |= bit;
                        flag[x][y + 1] |= bit;
                        flag[x][y + 2] |= bit;
                        flag[x + 1][y] |= bit;
                        flag[x + 1][y + 1] |= bit;
                        flag[x + 1][y + 2] |= bit;
                        flag[x + 2][y] |= bit;
                        flag[x + 2][y + 1] |= bit;
                        flag[x + 2][y + 2] |= bit;
                    }
                }
            }
        }
    }
}

/**
 * @brief 未決定箇所で、フラグだけでこれしかない場所をセットする
 *
 * @return int
 */
int judgeAndSet1(void)
{
    int resultCount = 0;
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (data[x][y] == 0)
            {
                switch (flag[x][y])
                {
                case 0b111111110:
                    data[x][y] = 1;
                    setFlag(x, y, 1);
                    resultCount++;
                    break;
                case 0b111111101:
                    data[x][y] = 2;
                    setFlag(x, y, 2);
                    resultCount++;
                    break;
                case 0b111111011:
                    data[x][y] = 3;
                    setFlag(x, y, 3);
                    resultCount++;
                    break;
                case 0b111110111:
                    data[x][y] = 4;
                    setFlag(x, y, 4);
                    resultCount++;
                    break;
                case 0b111101111:
                    data[x][y] = 5;
                    setFlag(x, y, 5);
                    resultCount++;
                    break;
                case 0b111011111:
                    data[x][y] = 6;
                    setFlag(x, y, 6);
                    resultCount++;
                    break;
                case 0b110111111:
                    data[x][y] = 7;
                    setFlag(x, y, 7);
                    resultCount++;
                    break;
                case 0b101111111:
                    data[x][y] = 8;
                    setFlag(x, y, 8);
                    resultCount++;
                    break;
                case 0b011111111:
                    data[x][y] = 9;
                    setFlag(x, y, 9);
                    resultCount++;
                    break;
                }
            }
        }
    }
    return resultCount;
}

/**
 * @brief 縦横の列で入りうる値のチェックをして値をセットする

 * @return int
 */
int judgeAndSet2(void)
{
    int resultCount = 0;

    // 上から順に横方向の列をチェックしていく
    for (int y = 0; y < 9; y++)
    {
        for (int n = 0; n < 9; n++)
        {
            WORD bit = 1 << n;
            int num = 0;
            for (int x = 0; x < 9; x++)
            {
                if ((data[x][y] == 0) && (~flag[x][y] & bit))
                {
                    num++;
                }
            }
            // k の数が一つだけならk+1をdataにセットする
            if (num == 1)
            {
                for (int x = 0; x < 9; x++)
                {
                    if ((data[x][y] == 0) && (~flag[x][y] & bit))
                    {
                        resultCount++;
                        data[x][y] = n + 1;
                        setFlag(x, y, n + 1);
                        break; // 一個セットしたら抜ける
                    }
                }
            }
        }
    }
    // 左から順に縦方向の数値をチェックしていく
    for (int x = 0; x < 9; x++)
    {
        for (int n = 0; n < 9; n++)
        {
            WORD bit = 1 << n;
            int num = 0;
            for (int y = 0; y < 9; y++)
            {
                if ((data[x][y] == 0) && (~flag[x][y] & bit))
                {
                    num++;
                }
            }
            // k の数が一つだけならk+1をdataにセットする
            if (num == 1)
            {
                for (int y = 0; y < 9; y++)
                {
                    if ((data[x][y] == 0) && (~flag[x][y] & bit))
                    {
                        resultCount++;
                        data[x][y] = n + 1;
                        setFlag(x, y, n + 1);
                        break; // 一個セットしたら抜ける
                    }
                }
            }
        }
    }
    return resultCount;
}

/**
 * @brief 3x3範囲で、入りうる値のチェックをし値をセットする
 * また、3x3範囲で2つか3つ同じ値が入り得る場合で、
 * かつ、その並んだ軸方向が同じであれば、
 * 軸方向の他の領域ではその値が入らない。
 * 3x3範囲でその値を仮置きできるため、
 * 仮置きした値のフラグをセットする
 * @return int
 */
int judgeAndSet3(void)
{
    int resultCount = 0;
    int num;
    // 仮置き判定用の構造体
    struct t_axis
    {
        int x;
        int y;
    } axis[9];

    for (int y = 0; y < 9; y += 3)
    {
        for (int x = 0; x < 9; x += 3)
        {
            for (int n = 0; n < 9; n++)
            {
                num = 0;
                WORD bit = 1 << n;
                for (int yy = 0; yy < 3; yy++)
                {
                    for (int xx = 0; xx < 3; xx++)
                    {
                        int xxx = x + xx;
                        int yyy = y + yy;
                        if ((data[xxx][yyy] == 0) && (~flag[xxx][yyy] & bit))
                        {
                            axis[num].x = xxx;
                            axis[num].y = yyy;
                            num++;
                        }
                    }
                }
                if (num == 1)
                {
                    for (int yy = 0; yy < 3; yy++)
                    {
                        for (int xx = 0; xx < 3; xx++)
                        {
                            int xxx = x + xx;
                            int yyy = y + yy;
                            if ((data[xxx][yyy] == 0) && (~flag[xxx][yyy] & bit))
                            {
                                resultCount++;
                                data[xxx][yyy] = n + 1;
                                setFlag(xxx, yyy, n + 1);
                            }
                        }
                    }
                }
                else if (num == 2)
                {
                    // 3x3の範囲で、現在調査中の数が２つか３つ入り得る場合
                    // x軸またはy軸が同じかどうかをチェックする
                    if (axis[0].x == axis[1].x)
                    {
                        // ２つのX軸が同じなので、垂直方向のフラグをセットする
                        setVFlagWithoutRange(axis[0].x, axis[0].y, n + 1);
                    }
                    else if (axis[0].y == axis[1].y)
                    {
                        // ２つのY軸が同じなので、水平方向のフラグをセットする
                        setHFlagWithoutRange(axis[0].x, axis[0].y, n + 1);
                    }
                }
                /*
                else if (num == 3)
                {
                    // 3x3の範囲で、現在調査中の数が２つか３つ入り得る場合
                    // x軸またはy軸が同じかどうかをチェックする
                    if (axis[0].x == axis[1].x && axis[0].x == axis[2].x)
                    {
                        // ３つのX軸が同じなので、垂直方向のフラグをセットする
                        setVFlagWithoutRange(axis[0].x, axis[0].y, n + 1);
                    }
                    else if (axis[0].y == axis[1].y && axis[0].y == axis[2].y)
                    {
                        // ３つのY軸が同じなので、水平方向のフラグをセットする
                        setHFlagWithoutRange(axis[0].x, axis[0].y, n + 1);
                    }
                }
                */
            }
        }
    }
    return resultCount;
}

int countZero(void)
{
    int zeroCount = 0;
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (data[x][y] == 0)
            {
                zeroCount++;
            }
        }
    }
    return zeroCount;
}

int judgeAndSet(void)
{
    int resultCount = 0;
    int tmp = 0;

    // 単純に 0 の箇所の未決定な数値が 1 つであれば、それを解としてセットする
    tmp = judgeAndSet1();
    resultCount += tmp;
#ifdef DEBUG
    printf("judgeAndSet1で%d箇所見つかった\r\n", tmp);
    printf("フラグを見て値をセットした結果を表示\r\n");
    printData();
    printBit();
#endif

    // 縦横方向で、残りの入り得る数値を調べてセットする
    tmp = judgeAndSet2();
    resultCount += tmp;
#ifdef DEBUG
    printf("judgeAndSet2で%d箇所見つかった\r\n", tmp);
    printf("縦横方向の入りうる値をチェックした結果を表示\r\n");
    printData();
    printBit();
#endif

    // 3x3範囲で残りの入り得る数値を調べてセットする
    tmp = judgeAndSet3();
    resultCount += tmp;
#ifdef DEBUG
    printf("judgeAndSet3で%d箇所見つかった\r\n", tmp);
    printf("3x3範囲で、入りうる値をチェックした結果を表示\r\n");
    printData();
    printBit();
#endif
    // 最終判定用にカウントを足す
    if (countZero() == 0)
    {
        // もうゼロが無いので全部見つかった
        printf("解けました\r\n");
        return 0;
    }
    else if (resultCount == 0)
    {
        // ゼロはあったけど、結果が見つからないときは解けない
        printf("解けませんでした\r\n");
        return -1;
    }
    else
    {
        // ゼロがあって、結果もあったのでまだ継続できるかも？
        return 1;
    }
}

int analyze(void)
{
    setVHFlag();
#ifdef DEBUG
    printf("縦横方向にflagを立てた後の状態を表示\r\n");
    printBit();
#endif
    setSquareFlag();
#ifdef DEBUG
    printf("３ｘ３領域のflagを立てた後の状態を表示\r\n");
    printBit();
#endif
    return (judgeAndSet());
}

void init(void)
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            flag[x][y] = 0;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (readData(argv[1]) == 0)
        // if (readData("dat0.txt") == 0)
        {
            int result;
            // 読めたので解析
            init();
            // 見つからなくて-1が返るか、全部見つかって0が返るまでanalyze()を呼び続ける
            do
            {
                result = analyze();
            } while (result > 0);
            printData();
        }
        else
        {
            // 読めなかったのでリターン
            return 0;
        }
    }
    else
    {
        // 引数が無いので使い方の表示
        printf("usage:\r\n");
        printf("sudoku file[ENTER]\r\n");
        return 0;
    }
}