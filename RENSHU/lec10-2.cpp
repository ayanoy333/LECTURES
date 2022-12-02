#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    int sum = 0;
    i = 1;
    printf("%d\r\n", i);

    for (i = 1; i <= 10; i++)
    {
        sum = sum + i;
        printf("%d\r\n", i);
    }
    printf("%d\r\n", sum);

    // f = f_prev + f_current
    // 1,2,3,5,8,13

    printf("1,");
    int cur = 1, prv = 1, tmp;
    for (i = 1; i <= 10; i++)
    {
        tmp = cur + prv;
        printf("%d,", tmp);
        prv = cur;
        cur = tmp;
    }
    printf("\r\n");
    for (i = -5; i <= 5; i++)
    {
        tmp = 25 - i * i;
        for (int j = 0; j < tmp; j++)
        {
            printf(" ");
        }
        printf("*\r\n");
    }
    return 0;
}