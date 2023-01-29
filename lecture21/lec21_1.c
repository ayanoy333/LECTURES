#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM 100             //定義　別名を付けられる　コンパイル前に100に置き換え

enum LIFEORTHING{
    UNDEF = -1,              //-1
    THING ,                  //0と同義
    LIFE                     //1
};

enum THINGS{
    WALL_PAPER,
    DESK                
};

struct NOUN
{
    int lifeOrThing;
    char name[40];
    int prop1;
}NOUN[NUM];                 //初期化

void init(void)
{
    for (int i = 0; i < NUM; i++)
    {
        NOUN[i].lifeOrThing = UNDEF;        //100個分初期化される
    }
    NOUN[0].lifeOrThing = THING;
    NOUN[0].prop1 = WALL_PAPER;
    strcpy(NOUN[0].name,"鳥の柄の壁紙");
    NOUN[1].lifeOrThing = THING;
    NOUN[1].prop1 = DESK;
    strcpy(NOUN[1].name,"子供用机");
}

int main (void)
{
    init();
    printf("%s\r\n",NOUN[0].name);
}