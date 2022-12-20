#include<stdio.h>
#include<stdlib.h>

int main (int argc,char **argv)
{
    if(argc != 3)
    {
        printf("bmi height weight\r\n");
        return (0);
    }
    float height,weight,bmi;    //float 変数名
    height = atof(argv[1]);
    weight = atof(argv[2]);
    bmi = weight/(height*height);
    printf("%f\r\n",bmi);
    return (0);
}