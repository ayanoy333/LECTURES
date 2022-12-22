#include <stdio.h>

typedef struct t_bargraph
{
    char name[80];
    int value;
}bargraph;

bargraph bg[3] = {
    {"chiba  ",4},
    {"saitama",9},
    {"gunma  ",1}};

    void dispBar(void)
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

    int main(int argc,char **argv)
    {
        dispBar();
    }
