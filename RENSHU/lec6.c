#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //複数のファイルを開くときは
#include <stdbool.h> //コンパイルするとき -o

#define BUFF_SIZE 10

typedef struct words
{
    char *word;
    int count;
    struct words *next;     //次の構造体、ワード
    struct words *prev;     //一個前の構造体
} t_words;

int main(int argc, char **argv)
{
    bool bFound;            //bool 真理値の２つをとる
    int readCount;

    FILE *fp;
    char buff[BUFF_SIZE];
    char wordbuff[2048];            //2048字入るバッファー
    char *wp = wordbuff;

    t_words *TopWord = (t_words *)malloc(sizeof(t_words));      //mallocはmemory allocationで、メモリを確保する命令
                                                                //動的メモリ確保 (t_words*)の部分はキャスト 別の型にすることができる
                                                                //mallocの戻り値は(void*)なので、(t_words*)にしている 
                                                                //mallocの引数はsizeof(t_words)となっていて、sizeofは型のサイズを返すことが出来る
                                                                //これによって、mallocで確保したt_words分のメモリを、TopWordsで指すようにしている
    TopWord->next = NULL;                                       //どこも指さない  初期化
    TopWord->prev = NULL;
    TopWord->word = NULL;
    TopWord->count = 0;

    t_words *LastWord = TopWord;                                //同じ所を指している　構造体のどこが空いてるかを指すのがLastWord

    for (int i = 1; i < argc; i++)                              //argv0はプログラム本体を指す　1からが本当の引数
                                                                // i++for文のループが終わって条件を満たしていれば次のループで実行される
    {
        printf("%sを読みます\r\n", argv[i]);
        fp = fopen(argv[i], "rb");                              //read binary 
        while (readCount = fread(buff, sizeof(char), BUFF_SIZE, fp))    //buff->buffer 記憶領域
        {
            //読み込んだ量がバッファのサイズより小さかったらバッファの残りを0ｘ00で埋めておく　ゴミをなくすための処理
            for (int j = readCount; j < BUFF_SIZE; j++)
                buff[j] = 0x00;

            char *p = &buff[0];                                 //単語をコピーするための一時的なポインター
            while (p != &buff[BUFF_SIZE])
            {
                while ((*p == 0x20 || *p == '\r' || *p == '\n') && p != &buff[BUFF_SIZE] && wp == &wordbuff[0]) //空白を飛ばすための処理
                    p++;
                //単語をwordbuffにコピーするがBUFF_SIZEまで達したらコピー途中でも一度やめる
                while ((*p != 0x20 && *p != '\r' && *p != '\n') && p != &buff[BUFF_SIZE])
                    *wp++ = *p++;

                if (*p == 0x20 || *p == '\r' || *p == '\n')
                {
                    int len = wp - &wordbuff[0] + 1;
                    *wp = 0x00;    // wordbuffの最後に0x00を足しておく
                    wp = wordbuff; // wpは先頭に戻す

                    // TopWordから検索
                    t_words *search = TopWord;
                    bFound = false;
                    while (search->word != NULL)
                    {
                        if (strcmp(search->word, wordbuff) == 0)
                        {
                            //見つかった
                            search->count++;
                            bFound = true;
                            break;
                        }
                        search = search->next;
                    }
                    if (!bFound)
                    {
                        //見つからなかったのでLastWordに文字をコピーしカウントを１にする
                        LastWord->word = (char *)malloc(len);
                        memcpy(LastWord->word, wordbuff, len);
                        LastWord->count = 1;
                        //次の入れ物を用意してLastWordを移動しておく
                        LastWord->next = malloc(sizeof(t_words));
                        LastWord->next->prev = LastWord;
                        LastWord = LastWord->next;
                        LastWord->next = NULL;
                    }
                }
                if (p == &buff[BUFF_SIZE])
                {
                    // BUFF_SIZEまで到達していたら抜けてファイルを読み直す
                    break;
                }
            }
        }
    }
    fclose(fp);
    //終わったので結果を表示する
    t_words *search = TopWord;
    printf("結果を表示します\r\n");
    while (search->word != NULL)
    {
        printf("%s\t%d\r\n", search->word, search->count);
        search = search->next;
    }
    //メモリーを最後から解放する
    do
    {
        if (search->word != NULL)
        {
            printf("[[%s]]を開放\r\n", search->word);
            free(search->word);
        }
        search = search->prev;
        free(search->next);
    } while (search->prev != NULL);

    printf("最後の一つを開放\r\n");
    printf("[[%s]]を開放", search->word);
    if (search->word != NULL)
        free(search->word);
    free(search);
}