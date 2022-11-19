#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct t_bingo
{
    int num;
    struct t_bingo *next;
    struct t_bingo *prev;
} bingo;

bingo TopBingo = {-1, NULL, NULL}; // TopBingoは値を入れないnextから

/**
 * @brief 最後に値を入れる
 * @param num
 */
void append(int num)
{
    bingo *pBingo = TopBingo.next;
    bingo *prev = &TopBingo;
    while (pBingo != NULL)
    {
        prev = pBingo;
        pBingo = pBingo->next;
    }
    pBingo = malloc(sizeof(bingo));
    pBingo->num = num;
    pBingo->next = NULL;
    pBingo->prev = prev;
    prev->next = pBingo;
}
/**
 * @brief TopBingoのnextから数えて、index番目のbingoの前後のprevとnextを繋いで
 * index 番目のbingoを消す
 * @param index
 */
int removeAt(int index)
{
    bingo *pBingo = TopBingo.next;
    int i = 0;
    while (pBingo != NULL && pBingo->next != NULL && i != index)
    {
        pBingo = pBingo->next;
        i++;
    }
    if (i != index || pBingo == NULL)
    {
        // index番目が存在しない場合はエラーとして-1を返す
        return -1;
    }
    if (pBingo->prev != NULL)
        pBingo->prev->next = pBingo->next;
    if (pBingo->next != NULL)
        pBingo->next->prev = pBingo->prev;
    free(pBingo);
    return 0;
}
int getAt(int index)
{
    bingo *pBingo = TopBingo.next;
    int i = 0;
    while (pBingo != NULL && pBingo->next != NULL && i != index)
    {
        pBingo = pBingo->next;
        i++;
    }
    if (i != index || pBingo == NULL)
    {
        // index 番目が存在しない場合はエラーとして-1を返す
        return -1;
    }
    return pBingo->num;
}
int clearAll(void)
{
    bingo *pBingo = TopBingo.next;
    while (removeAt(0) != -1)
        ;
}
int main(int argc, char **argv)
{
    int i;

    printf("数字を1から3まで入れてみる\r\n");
    bingo *pBingo = TopBingo.next;
    for (i = 1; i <= 3; i++)
    {
        append(i);
    }
    printf("入れた数字を表示してみる\r\n");
    pBingo = TopBingo.next;
    while (pBingo != NULL)
    {
        printf("%d ", pBingo->num);
        pBingo = pBingo->next;
    }
    printf("\r\n\r\n");
    printf("0番目を消してから1番目を消す、結果2番目になる\r\n");
    removeAt(0);
    removeAt(1);
    pBingo = TopBingo.next;
    while (pBingo != NULL)
    {
        printf("%d ", pBingo->num);
        pBingo = pBingo->next;
    }
    printf("\r\n\r\n");

    clearAll();
    pBingo = TopBingo.next;
    while (pBingo != NULL)
    {
        printf("%d ", pBingo->num);
        pBingo = pBingo->next;
    }
    printf("\r\n\r\n");

    //ここから本番
    printf("1から75までの値を入れる\r\n");
    for (i = 1; i <= 75; i++)
    {
        append(i);
    }
    printf("\r\n\r\n");
    printf("0-74に入ったはずなので、それを表示する\r\n");
    for (i = 0; i < 75; i++)
    {
        printf("%d ", getAt(i));
    }
    printf("\r\n\r\n");

    printf("乱数を生成し、その乱数の位置にある値を表示するとともにその位置を消去する\r\n");
    int rndnum;
    srand(time(0));

    for (i = 0; i < 75; i++)
    {
        //乱数を生成する
        rndnum = rndnum = rand() % (75 - i);
        printf("%d ", getAt(rndnum));
        removeAt(rndnum);
    }
    printf("\r\n\r\n");

    printf("重複しない乱数が75個表示される\r\n");

    return 0;
}