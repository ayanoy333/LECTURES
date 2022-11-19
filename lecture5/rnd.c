#include <stdlib.h>
#include <time.h>

int getRnd(int from, int to)
{
    if (from == to)
    {
        return from;
    }
    int ret = 0;
    srand(time(0));
    ret = from + rand() % (to - from + 1);
    return ret;
}