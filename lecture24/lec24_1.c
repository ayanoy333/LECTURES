#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i,j;
    unsigned char c[10][10];

    c[0][0] = 0x10;
    c[0][1] = 0x02;
    c[0][2] = 0x03;
    c[0][3] = 0x04;
    c[0][4] = 0x05;
    c[0][5] = 0x06;
    c[0][6] = 0x07;
    c[0][7] = 0x08;
    c[0][8] = 0x09;
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
