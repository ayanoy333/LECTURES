#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    int sum,sume,sumo;
    sum = 0;
    sume = 0;
    sumo = 0;
    for (i = 1; i <= 100; i++)
    {
        sum = sum + i;
    }
    printf("%d\r\n", sum);
    sum = 0; //初期化
    for (i = 1; i <= 100; i++)
    {
        if (i % 2 == 0) // ifは条件文
        {
            sum = sum + i;
        }
    }

    printf("%d\r\n", sum);

    sum = 0;
    for (i = 1; i <= 100; i++)
    {
        if (i % 2 == 1)
        {
            sum = sum + i;
        }
    }
    printf("%d\r\n", sum);
    sum = 0;
    for(i = 1;i<=100;i++){
        sum = sum + i;       //sum+=i でも同じ
        if(i%2 == 0){
            sume = sume + i;
        }else{          //そうじゃないとき　　else if でもかける　else if (i%2 == 1)
            sumo = sumo + i;
        }
    }
    printf("1～100まで%d\r\n", sum);
    printf("偶数のみ%d\r\n", sume);
    printf("奇数のみ%d\r\n", sumo);
    return 0;
}
