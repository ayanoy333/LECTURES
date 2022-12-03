#include <stdio.h>
#include <string.h>
#include <vector>

class dispBargraph
{
private:
    typedef struct t_bargraph
    {
        char name[80];
        int value;
    }bargraph;
    std::vector<bargraph> bars;     //vectorは<>の中を可変長データとして管理できる管理できる

public:
/**
 * @brief name value　を受け取ってbargraph型変数に値をセットしてbarsにpushback
 * 
 * @param name
 * @param val
 */
void append(const char *name,int val)
{
    bargraph b;     //bargraph
}





}