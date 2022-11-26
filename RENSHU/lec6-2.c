#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFF_SIZE 8192
#define WORD_BUFF_SIZE 2048

typedef struct words
{
    char *word;
    int count;
    struct words *next;
    struct words *prev;  
} t_words;

int main (int argc, char **argv)
{
    bool bFound;
    int readCount;

    FILE *fp;
    char buff[BUFF_SIZE];
    char wordbuff[WORD_BUFF_SIZE];
    char *wp = wordbuff;

    t_words *TopWord = (t_words*)malloc(sizeof(t_words));
    TopWord->next = NULL;
    TopWord->prev = NULL;
    TopWord->word = NULL;
    TopWord->count = 0;

    t_words *LastWord = TopWord;

    //for(int i = 1; i < argc; i++)
    //{

    for (int i = 1; i < argc; i++)
    {
        printf("%sを読みます\r\n",argv[i]);
        fp = fopen(argv[i],"rb");
        while (readCount = fread(buff,sizeof(char),BUFF_SIZE,fp))
        {
            //読み込んだ量がバッファのサイズより小さかったら、バッファの残りを0x00で埋めておく
            for (int j =readCount; j< BUFF_SIZE; j++)
            buff [j] = 0x00;

            char *p = &buff[0];
            while (p != &buff[BUFF_SIZE])
            {

            while ((*p == 0x20 || *p == '\r' || *p == '\n')&& p != &buff[BUFF_SIZE]&& wp == &wordbuff[0])
            p++;

            //単語をwordbuffにコピーするが、BUFF_SIZEまで達したら、コピー途中でも一度やめる
            while ((*p != 0x20 && *p != '\r'&& *p != '\n')&& p != &buff[BUFF_SIZE])
            *wp++ = *p++;

            if (*p == 0x20 || *p == '\r' || *p == '\n')
            {
                int len = wp - &wordbuff[0] +1;
                *wp = 0x00;    //wordbuff の最後に0x00を足しておく
                wp = wordbuff;  //wpは先頭に戻す

                //TopWord から検索
                t_words *search = TopWord;
                bFound = false;
                while (search->word != NULL)
                {
                    if (strcmp(search->word,wordbuff) == 0)
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
                    //見つからなかったのでLastWordに文字をコピーし、カウントを１にする
                    LastWord->word = (char*)malloc(len);
                    memcpy(LastWord->word,wordbuff,len);
                    LastWord->count = 1;
                    // 次の入れ物を用意してLastWord を移動しておく
                     LastWord->next = malloc(sizeof(t_words));
                     LastWord->next->prev = LastWord;
                     LastWord = LastWord->next;
                     LastWord->next = NULL;
    
                }
            }
            if (p == &buff[BUFF_SIZE])
            {
                //BUFF_SIZEまで到達していたら抜けてファイルを読み直す
                break;
            }
            }
            
         }
    }
    fclose(fp);
    //}
    //終わったので結果を表示する
    t_words *search = TopWord;
    printf("結果を表示します\r\n");
    while (search->word != NULL)
    {
        printf("%s\t%d\r\n", search->word, search->count);
        search = search->next;
    }
    //メモリーを最後から開放する
    do
    {
        if (search->word != NULL){
            printf("[[%s]]を開放\r\n",search->word);
            free (search->word);
        }
        search = search->prev;
        free(search->next);
    }while (search->prev != NULL);

    printf("最後の一つを開放\r\n");
    printf("[[%s]]を開放", search->word);
    if (search->word != NULL)
    free (search->word);
    free(search);    

}