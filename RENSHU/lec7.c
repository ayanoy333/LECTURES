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
}