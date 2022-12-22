#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief 
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc,char **argv)
{
    //int型ポインタ
    int a;
    int *pa = &a;

    *pa = 10;
    printf("a = %d,*pa = %d\r\n",a,*pa);
    //両方10。次はint型配列とポインタ

    int *b[3];
    int *pb = b;    //int *pb = &b[0];でも同じ
    *pb = 1;        //ポインタは相対位置からもアクセス可能
    *(pb + 1) = 2;  //配列の添え字
    *(pb + 2) = 3;
    printf("b[0] = %d,b[1] = %d,b[2] = %d\r\n",b[0],b[1],b[2]);
    
    b[0] = 10;
    b[1] = 20;
    b[2] = 30;

    printf("*(pb + 0) = %d,*(pb + 1) = %d,*(pb + 2) = %d\r\n",*(pb + 0),*(pb + 2));

    char buff [10];
    char *pbuff = buff;     //char *pbuff = &buffでも同じ
    strcpy(buff,"aiueo");   //文字列型コピー

    printf("pbuff = %s\r\n",pbuff);     //%s文字列を出力
    printf("buff = %s\r\n",buff);

    //まずは定義だけする
    struct point
    {
        int x;
        int y;
        int z;
    };
    //使うときはstruct付きで実態の定義をする
    struct point pt;
    pt.x = 10;
    pt.y = 20;
    pt.z = 30;
    printf("pt = (%d,%d,%d)\r\n",pt.x,pt.y,pt.z);
    
    //構造体の配列を作る
    struct point pts_a[2];
    pts_a[0].x = 1;
    pts_a[0].y = 2;
    pts_a[0].z = 3;
    pts_a[1].x = 10;
    pts_a[2].y = 20;
    pts_a[3].z = 30;
    printf("pts_a[0] = (%d,%d,%d),pts_a[1] = (%d,%d,%d)\r\n",
    pts_a[0].x,pts_a[0].y,
    pts_a[0].z,pts_a[0].x,
    pts_a[1].y,pts_a[0].z);

    //構造体の配列宣言と初期化を同時にする
    struct point pts_b[3] = {
        {1,2,3},
        {10,20,30},
        {100,200,300}};

        printf("pts_b[0] = (%d,%d,%d),pts_b[1] = (%d,%d,%d),pts_b[2] = (%d,%d,%d)\r\n",
          pts_b[0].x,pts_b[0].y,pts_b[0].z,
          pts_b[1].x,pts_b[1].y,pts_b[1].z,
          pts_b[2].x,pts_b[2].y,pts_b[2].z);

          typedef unsigned char BYTE;

          struct t_color
          {
            BYTE R;
            BYTE G;
            BYTE B;
          };
          struct t_color col = {10,20,30};
          printf("col = (%ud,%ud,%ud)\r\n",col.R,col.G,col.B);
        typedef struct t_whiskey
          {
            char name[80];
            int price;
          }whiskey;

          //以後whiskeyという型をｔ_whiskeyとして使える
          //char name[80]のようにサイズが固定なら文字列の初期化も可能
        
        whiskey whiskeys[3] = {
            {"Jack Daniel",180},
            {"Black Nikka",300},
            {"Talisker",450},
        };

        //構造体の中のメンバーにアクセスする場合実体があれば.でアクセス可能

        printf("whiskeys[0] = %s,%d\r\n",
        whiskeys[0].name,whiskeys[0].price);
        printf("whiskeys[1] = %s,%d\r\n",
        whiskeys[1].name,whiskeys[1].price);
        printf("whiskeys[2] = %s,%d\r\n",whiskeys[2].name,whiskeys[2].price);

        //構造体のポインタを使ったメンバーへのアクセスは->になる
        //10個分のメモリー確保
        whiskey*pwhiskey = malloc(sizeof(whiskey)*10);
        strcpy(pwhiskey->name,"abcde");
        pwhiskey->price = 100;

        pwhiskey++; //インクリメントすると構造体サイズ分だけポインタが移動
        // pwhiskey = pwhiskwy + 1 でも同じ　*(pwhiskey + 1 )->nameでも同じ
        strcpy(pwhiskey->name,"fghij");
        pwhiskey->price = 200;
        pwhiskey++;

        strcpy(pwhiskey->name,"klmo");
        pwhiskey->price = 300;

        printf("pwhiskey = %s,%d,\r\n",pwhiskey->name,pwhiskey->price);
        pwhiskey--;//
        printf("pwhiskey = %s,%d\r\n",pwhiskey->name,pwhiskey->price);
        pwhiskey--;//
        printf("pwhiskey = %s,%d\r\n",pwhiskey->name,pwhiskey->price);

        //pwhiskeyが戻ったので相対アクセスしてみる
        printf("pwhiskey + 0 = %s,%d\r\n",(pwhiskey + 0)->name,(pwhiskey + 0)->price);
        printf("pwhiskey + 1 = %s,%d\r\n",(pwhiskey + 1)->name,(pwhiskey + 1)->price);
        printf("pwhiskey + 2 = %s,%d\r\n",(pwhiskey + 2 )->name,(pwhiskey + 2)->price);

        free(pwhiskey);
    }


