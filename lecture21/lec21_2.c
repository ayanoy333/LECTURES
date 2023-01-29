#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM 100             //定義　別名を付けられる　コンパイル前に100に置き換え
int cnum = 0;

enum LIFEORTHING{
    UNDEF = -1,              //-1       変数ではなく定義なのでわかりやすいように大文字
    THING,                  //0と同義
    LIFE                     //1
};

enum THINGS_KIND{
    WALL_PAPER,
    DESK                
};

enum LIVES_KIND{
    CAT,
    DOG,
    BIRD            
};

struct NOUN
{
    int lifeOrThing;
    char name[40];
    int kind;
}NOUN[NUM];                 //初期化 0からNUM -1番目までしか作られないからNUM番目はエラー

int setNoun(int lt,int kind,char*name)          //*name はinitの中身にアクセスしてる
{
    int ret = 0;              //初期化,宣言
    if (cnum >= NUM) 
    {
        ret = -1;             //異常終了
    }else{
        NOUN[cnum].lifeOrThing = lt;
        NOUN[cnum].kind = kind;
        strcpy(NOUN[cnum].name,name);
        cnum++;
    }
    return ret;
}

void init(void)
{
    for (int i = 0; i < NUM; i++)           //初期化；継続する際の論理式；継続時にする処理
    {
        NOUN[i].lifeOrThing = UNDEF;        //NUM 個分初期化される
    }
    setNoun(THING,WALL_PAPER,"鳥の柄の壁紙");
    setNoun(THING,DESK,"子供用机");
    setNoun(LIFE,CAT,"ロシアンブルー");
    setNoun(LIFE,DOG,"柴犬");
    setNoun(LIFE,BIRD,"インコ");
    setNoun(LIFE,CAT,"アメショ");
}

int main (void)
{
    init();                                //さっき定義したからinitが呼べる
    for (int i = 0; NOUN[i].lifeOrThing != UNDEF; i++)      //i＝０からNOUNがUNDEFではない間、ループする　論理式trueの間はループ継続
    {
        printf("%s\r\n",NOUN[i].name);
    }
    
}