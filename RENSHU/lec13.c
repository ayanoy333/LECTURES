#include<stdio.h>

int main(int argc,char **argv)
{
    typedef struct t_bargraph
    {
        char name[80];
        int value;
    }bargraph;
    bargraph bg[3] = {
        {"chiba  ",9},
        {"saitama",8},
        {"gunma  ",6}
    };
    for (int i = 0; i < 3; i++)
    {
        printf("%s\t",bg[i].name);
        for(int j = 0; j < bg[i].value; j++)
        {
            printf("*");
        }
        printf("\r\n");
    }
}