#include <stdio.h>
/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{
    printf("argc=%d\r\n", argc);
    if (argc > 0)
    {
        printf("argv[0]=%s\r\n", argv[0]);
    }
    if (argc > 1)
    {
        printf("argv[1]=%s\r\n", argv[1]);
    }
    return 0;
}