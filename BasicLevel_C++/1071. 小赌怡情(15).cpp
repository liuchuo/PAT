1071. 小赌怡情(15)
常言道“小赌怡情”。这是一个很简单的小游戏：首先由计算机给出第一个整数；然后玩家下注赌第二个整数将会比第一个数大还是小；玩家下注t个筹码后，计算机给出第二个数。若玩家猜对了，则系统奖励玩家t个筹码；否则扣除玩家t个筹码。
注意：玩家下注的筹码数不能超过自己帐户上拥有的筹码数。当玩家输光了全部筹码后，游戏就结束。
输入格式：
输入在第一行给出2个正整数T和K（<=100），分别是系统在初始状态下赠送给玩家的筹码数、以及需要处理的游戏次数。随后K行，每行对应一次游戏，顺序给出4个数字：
n1 b t n2
其中n1和n2是计算机先后给出的两个[0, 9]内的整数，保证两个数字不相等。b为0表示玩家赌“小”，为1表示玩家赌“大”。t表示玩家下注的筹码数，保证在整型范围内。
输出格式：
对每一次游戏，根据下列情况对应输出（其中t是玩家下注量，x是玩家当前持有的筹码量）：
玩家赢，输出
Win t!  Total = x.
玩家输，输出
Lose t.  Total = x.
玩家下注超过持有的筹码量，输出
Not enough tokens.  Total = x.
玩家输光后，输出
Game Over.
并结束程序。
输入样例1：
100 4
8 0 100 2
3 1 50 1
5 1 200 6
7 0 200 8
输出样例1：
Win 100!  Total = 200.
Lose 50.  Total = 150.
Not enough tokens.  Total = 150.
Not enough tokens.  Total = 150.
输入样例2：
100 4
8 0 100 2
3 1 200 1
5 1 200 6
7 0 200 8
输出样例2：
Win 100!  Total = 200.
Lose 200.  Total = 0.
Game Over.

分析：有什么好分析的呢？

#include <iostream>
using namespace std;
int main() {
    int T = 0, K = 0, n1 = 0, n2 = 0, b = 0, t = 0;
    scanf("%d %d", &T, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        if (T == 0) {
            printf("Game Over.\n");
            return 0;
        } else if (t > T) {
            printf("Not enough tokens.  Total = %d.\n", T);
        } else if (n2 > n1) {
            if (b == 1) {
                T += t;
                printf("Win %d!  Total = %d.\n", t, T);
            } else {
                T -= t;
                printf("Lose %d.  Total = %d.\n", t, T);
            }
        } else if (n2 < n1) {
            if (b == 1) {
                T -= t;
                printf("Lose %d.  Total = %d.\n", t, T);
            } else {
                T += t;
                printf("Win %d!  Total = %d.\n", t, T);
            }
        }
    }
    return 0;
}