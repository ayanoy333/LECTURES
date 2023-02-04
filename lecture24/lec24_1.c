#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i,j;
    unsigned char c[10][10];

    // 表示部
    for (j=0;j<10;j++){
        for(i=0;i<10;i++){
            printf("%02x ",c[j][i]);
        }
        printf("\r\n");
    }
}
