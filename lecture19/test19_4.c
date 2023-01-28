#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int sum = 0, oddsum = 0, evensum = 0; // 初期化
    for (int i = 1; i <= 100; i++)
    {
        printf("i = %d, ", i);
        sum += i; // sum = sum + i　と同じ
        printf("sum = %d\r\n", sum);
        if (i % 2) // 2で割った剰余がある＝奇数、ならtrue　論理式　i%2 == true でも同じ　0はfalseと同じ、1はtrueと同じ
        {
            oddsum += i;
        }
        else // ↑以外、偶数　false == trueは偽　　 代入ではなく論理式　どっちかがfalseだったら偽
        {
            evensum += i;
        }
    }
    printf("sum = %d, oddsum = %d, evensum = %d\r\n", sum, oddsum, evensum);
    printf("n(n+1)/2 = %d\r\n", 100 * (100 + 1) / 2);
}