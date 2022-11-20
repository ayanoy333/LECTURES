#include <stdio.h>
#include <string.h>
#include <vector>

class dispBargraph
{
private:                //外から見られない
    typedef struct t_bargraph
    {
        char name[80];
        int value;
    } bargraph;
    std::vector<bargraph> bars;      //vectorは<>の中身のタイプを可変長データとして管理できる
                  
public:                             //外から見られる
    void append(const char *name, int val)
    {
        bargraph b;
        strcpy(b.name, name);
        b.value = val;
        bars.push_back(b);
    }
    void dispBar(void)
    {
        for (int i = 0; i < bars.size(); i++)
        {
            printf("%s\t", bars[i].name);
            for (int j = 0; j < bars[i].value; j++)
            {
                printf("*");
            }
            printf("\r\n");
        }
    }
};

int main(int argc, char **argv)
{
    dispBargraph b;             //外から見られるものを呼んだ　構造体に追加
    b.append("chiba   ", 10);
    b.append("saitama ", 20);
    b.append("kanagawa", 30);
    b.append("tokyo   ", 100);

    b.dispBar();               //構造体の中身を表示
}