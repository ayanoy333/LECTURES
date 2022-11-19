#include <stdio.h>
#include <string.h>

int main(int argc,char**argv)
{
    char str[80];
    strcpy(str,"Hello World\r\n");
    printf("%s",str);
    
    char *a = &str[6];
    strcpy(a,"Earth\r\n");
    printf("%s",str);

    return 0;
}