#include<stdio.h>
#include<stdlib.h>

int main (int argc, char **argv)
{
    if (argc != 3)
    {
        printf("bmi height weight\r\n");
        return (0);
    }
    float height,weight,bmi;    //float　浮動少数
    height = atof(argv[1]);     //atof を使ってfloatに変換
    weight = atof(argv[2]);
    bmi = weight/(height*height);
    printf("%f\r\n",bmi);       //%f floatとして表示する
    return (0);
}