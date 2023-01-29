#include<stdio.h>
#include<stdlib.h>

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
    for (int i = -10; i<= 10; i++)
    {
        printf("power(%d,2) = %d\r\n", i,power(i,2));
    }
    
}