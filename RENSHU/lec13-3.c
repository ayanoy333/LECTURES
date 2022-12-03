#include <stdio.h>

typedef struct t_bargraph
{
    char name[80];
    int value;
}bargraph;

void dispBar(bargraph*bg)       //bgのアドレスを受け取った
{
    for (int i = 0; i < 3; i++)
    {
        printf("%s\t",bg[i].name);
        for (int j = 0; j < bg[i].value; j++)
        {
            printf("*");
        }
        printf("\r\n");
    }
}
int main (int argc,char **argv)
{
    bargraph bg[3] = {
        {"chiba  ",8},
        {"saitama",12},
        {"gunma  ",20}};
        dispBar(bg);
}

