#include <stdio.h>
#include <string.h>
#include <vector>   //ベクトル

class dispBargraph
{
private:                //外から見られない
    typedef struct t_bargraph
    {
        char name[80];
        int value;
    } bargraph;
    std::vector<bargraph> bars;      //vectorは<>の中身のタイプを可変長データとして管理できる bargraph型を可変長で保持pushback等可能
                  
public:                             //外から見られる
    /**
     * @brief nameとvalueを受け取ってbargraph型変数に値をセットしbarsにpushbackする
     * 
     * @param name 
     * @param val 
     */
    void append(const char *name, int val)  
    {
        bargraph b; //bargraph型変数ｂを宣言
        strcpy(b.name, name);   //b.nameにnameをコピー
        b.value = val;          //b.valにセット
        bars.push_back(b);      //barsにpushback
    }
    /**
     * @brief 名前を表示しbarを表示
     * 
     */
    void dispBar(void)
    {
        for (int i = 0; i < bars.size(); i++)   //1つでも入ってればfor文の中に入れる
        {
            printf("%s\t", bars[i].name);   //barsのnameを表示する
            for (int j = 0; j < bars[i].value; j++) // barsのvalueの分だけ*を表示
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