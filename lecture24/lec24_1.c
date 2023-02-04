#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i,j;
    unsigned char c[10][10];

    c[0][0] = 0x01;
    c[0][1] = 0x2;
    c[0][2] = 0x3 ;
    c[0][3] = 0x4;
    c[0][4] = 0x5 ;
    c[0][5] = 0x6;
    c[0][6] = 0x7 ;
    c[0][7] = 0x8;
    c[0][8] = 0x9 ;
    c[0][9] = 0x10;
    c[1][0] = 0x11;
    // 表示部
    for (j=0;j<10;j++){
        for(i=0;i<10;i++){
           printf("%02x ",c[j][i]);
        }
        printf("\r\n");               //10ずつの改行
    }
}
