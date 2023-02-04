#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i,j;
    int c[10];

    int *pc = &c[0];
    printf("address of c = %x\r\n", pc);
    for (i = 0; i < 10; i++)
    {
        c[i] = 0x01234567;
    }

    int cc[3][16];
    pc = &cc[0];
    printf("address of cc = %x\r\n", pc);
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 10; i++)
        {
            cc[j][i] = 0xff;
        }
        for (; i < 16; i++)
        {
            cc[j][i] = 0xaa;
        }
    }

    int ccc[5][5];
    pc = &ccc[0];
    printf("address of ccc = %x\r\n", pc);
    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 3; i++)
        {
            ccc[j][i] = 0xaa;
        }
        for (; i < 5; i++)
        {
            ccc[j][i] = 0xbb;
        }
    }

    *pc = 0xBB;
    *(pc+5) = 0xCC;

    return 0;
}