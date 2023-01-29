#include <stdio.h>
#include <stdlib.h>

int power(int x, int n)
{
    int result = x;
    for (int i = 1; i < n; i++)
    {
        result *= x;     // result = result * x
    }
    return result;
}

int main(int argc, char **argv)
{
    printf("power(2,3) = %d\r\n", power(2, 3));
}