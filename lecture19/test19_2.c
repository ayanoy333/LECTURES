#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int x, y;
    for (int i = 0; i < 10; i++)
    {
        x = i;
        y = x * x;
        printf("(x,y) = (%d,%d)\r\n", x, y);
    }
}