#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 100 // 定義　別名を付けられる　コンパイル前に100に置き換え
#define ALL -99 // enumの値と絶対に被らない値
int cnum = 0;

enum LIFEORTHING
{
    UNDEF = -1, //-1
    THING,      // 0と同義
    LIFE        // 1
};

enum KIND
{
    WALL_PAPER,
    DESK,
    CHAIR,
    CUTLERY,
    ANIMAL,
    BOOK_SHELF
};

enum PROP
{
    PROP_UNDEF,
    CAT,
    DOG,
    BIRD,
    SKY,
    FLOWER
};

class world // 構造体と違って、変数の型セットだけじゃなくて、関数も１セット（C++ではカプセル化言う）にしたもの
{
private:
    struct NOUN // 構造体は複数の型を１セットにしたもの
    {
        int lifeOrThing;
        char name[40];
        int kind;
        int prop;
    } NOUN[NUM]; // 初期化

public:
    int setNoun(int lt, int kind, int prop, char *name) //*name はinitの中身にアクセスしてる
    {
        int ret = 0; // 初期化,宣言
        if (cnum >= NUM)
        {
            ret = -1; // 異常終了
        }
        else
        {
            NOUN[cnum].lifeOrThing = lt;
            NOUN[cnum].kind = kind;
            NOUN[cnum].prop = prop;
            strcpy(NOUN[cnum].name, name);
            cnum++;
        }
        return ret;
    };

    world()     // コンストラクタ：クラスが生成されたときに自動的に実行される（絶対パブリックに置くこと）
    {
        for (int i = 0; i < NUM; i++) // 変化式－＞2回目以降forに戻ってきたときになにをするか
        {
            NOUN[i].lifeOrThing = UNDEF; // 100個分初期化される
        }

        setNoun(THING, WALL_PAPER, BIRD, "鳥の柄の壁紙");
        setNoun(THING, WALL_PAPER, FLOWER, "花柄の壁紙");
        setNoun(THING, DESK, PROP_UNDEF, "子供用机");
        setNoun(THING, CHAIR, PROP_UNDEF, "まわる椅子");
        setNoun(THING, BOOK_SHELF, FLOWER, "花柄の本棚");
        setNoun(LIFE, ANIMAL, CAT, "ロシアンブルー");
        setNoun(LIFE, ANIMAL, DOG, "柴犬");
        setNoun(LIFE, ANIMAL, BIRD, "インコ");
        setNoun(LIFE, ANIMAL, CAT, "アメショ");
    };

    void showNoun(int lt, int kind, int prop)
    {
        for (int i = 0; NOUN[i].lifeOrThing != UNDEF; i++)
        {
            if ((NOUN[i].lifeOrThing != lt) && (lt != ALL))
            {
                continue; // 次のfor文に続ける　　　breakはforを抜けて終わる
            }
            if ((NOUN[i].kind != kind) && (kind != ALL))
            {
                continue;
            }
            if ((NOUN[i].prop != prop) && (prop != ALL))
            {
                continue;
            }
            printf("%s\r\n", NOUN[i].name);
        }
    };
};

int main(void)
{
    world w;
    w.showNoun(ALL, ALL, CAT);
    printf("\r\n");
    w.setNoun(THING,BOOK_SHELF,CAT,"猫の本棚");
    w.showNoun(ALL, ALL, CAT);
}