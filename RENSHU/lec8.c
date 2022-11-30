#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct t_bingo
{
    int num;
    struct t_bingo *next;
    struct t_bingo *prev;
}bingo;

bingo TopBingo = {-1,NULL,NULL};    //Topbingoは値を入れない

/**
 * @brief  最後に値を入れる
 * @param num
 */
void append (int num)
{
    bingo*pBingo = TopBingo.next;
    bingo*prev = &TopBingo;
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
 * @brief TopBingoのnextから数えてindex番目のbingoの前後の
 * prevとnextを繋いでindex番目のbingoを消す
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
        //index番目が存在しない場合エラーとして-1を返す
        return -1;
    }
    if (pBingo->prev != NULL)
        pBingo->prev->next = pBingo->next;
    if(pBingo->next != NULL)
    pBingo->next->prev = pBingo->prev;
    free(pBingo);
    return 0;
}
int getAt(int index)
{
    bingo *pBingo = TopBingo.next;
    int i = 0;
    while(pBingo != NULL && pBingo->next != NULL && i != index)
    {
        pBingo = pBingo->next;
        i++;
    }
    if(i !=)
}