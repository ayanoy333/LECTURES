#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 
 * @param argc
 * @param argv
 * @return int
 */
int main (int argc,char **argv)
{
    //まずint型ポインタ
    int a;
    int *pa = &a;

    *pa = 10;
    printf("a = %d,*pa = %d\r\n",a,*pa);
    //どちらにも１０が表示される
    //次にint型配列とポインタ

    int b[3];
    int *pb = b; //int *pb = &b[0]; でも同じ
    *pb = 1;     //ポインタはこのようにpbからの相対位置の指定でもアクセス可能
    *(pb + 1) = 2; //考え方は配列の添え字
    *(pb + 2) = 3;
    printf("b[0] = %d,b[1] = %d, b[2] = %d\r\n", b[0],b[1],b[2]);

    b[0] = 10;
    b[1] = 20;
    b[2] = 30;

    printf("*(pb + 0) = %d,*(pb + 1) = %d,*(pb + 2) = %d\r\n",*(pb + 0),*(pb + 2));

    //次はchar型配列とポインタ

    char buff[10];
    char *pbuff = buff;  //char *pbuff = &pbuffでも同じ
    strcpy(buff,"aiueo");

    printf("pbuff = %s\r\n",pbuff);  // %sなので*pbuffではなくてpbuff
    printf("buff = %s/r/n",buff);

    //構造体の定義の仕方 １　まずは定義だけする
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
    printf("pts_a[0] = (%d,%d,%d), pts_a[1] = (%d,%d,%d)\r\n",
    pts_a[0].x, pts_a[0].y,
    pts_a[0].z, pts_a[1].x,
    pts_a[1].y, pts_a[1].z);

    //構造体の配列宣言と初期化を同時にする
    struct point pts_b[3] = {
        {1,2,3},
        {10,20,30},
        {100,200,300}};

        printf("pts_b[0] = (%d,%d,%d),pts_b[1] = (%d,%d,%d), pts_b[2] = (%d,%d,%d)\r\n",
        pts_b[0].x,pts_b[0].y,pts_b[0].z,
        pts_b[1].x,pts_b[1].y,pts_b[1].z,
        pts_b[2].x,pts_b[2].y,pts_b[2].z);

        //tyepdefは#defineと違って自作の型に新しい名前を付けられる
        //#defineは、文字を置き換えるだけ
        typedef unsigned char BYTE;

        struct t_color
        {//ここにｔ_を付けるのが正しい
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
        } whiskey;

        //以後whiskeyという型をstruct t_whiskeyとして使える
        //char name[80]のように名前のサイズが固定(80 byte)なら文字列の初期化も可能
        whiskey  whiskeys[3] = {
            {"Jack Daniel",180},
            {"Black Nikka",300},
            {"Talister,",450},
        };
        //ここでデバックしてnameの確認

        //構造体の中のメンバーにアクセスする場合実態があればドットでアクセスできる

        printf("whiskeys[0] = %s,%d/r/n",
        whiskeys[0].name,whiskeys[0].price);
        printf("whiskeys[1] = %s,%d\r\n",
        whiskeys[1].name,whiskeys[1].price);
        printf("whiskeys[2] = %s,%d/r/n",whiskeys[2].name,whiskeys[2].price);




        //構造体のポインタを使った場合メンバーへのアクセスは->になる
        //10個分のメモリー確保
        whiskey *pWhiskey = malloc(sizeof(whiskey)*10);
        strcpy(pWhiskey->name,"abcde");
        pWhiskey->price = 100;

        pWhiskey++; //インクリメントすると構造体サイズ分だけポインタが移動
        // pwhiskey = pWhiskey+1でも同じ　*(pWhiskey +1)->nameでも同じ
        strcpy(pWhiskey->name,"fghij");
        pWhiskey->price = 200;
        pWhiskey++;

        strcpy(pWhiskey->name,"klmo");    
        pWhiskey->price = 300;

        printf("pWhiskey = %s,%d\r\n",pWhiskey->name,pWhiskey->price);
        pWhiskey--; //
        printf("pWhiskey = %s,%d\r\n",pWhiskey->name,pWhiskey->price);
        pWhiskey--; //
        printf("pWhiskey = %s,%d\r\n",pWhiskey->name,pWhiskey->price);

        //pWhiskeyが戻ったので相対アクセスしてみる
        printf("pWhiskey + 0 = %s,%d\r\n",(pWhiskey + 0 )->name,(pWhiskey + 0 )->price);
        printf("pWhiskey + 1 = %s,%d\r\n",(pWhiskey + 1 )->name,(pWhiskey + 1 )->price);
        printf("pWhiskey + 2 = %s,%d\r\n",(pWhiskey + 2 )->name,(pWhiskey + 2 )->price);
      

      //最後にメモリ解放pWhiskeyが元の位置なのでちゃんと解放される
      free(pWhiskey);
}