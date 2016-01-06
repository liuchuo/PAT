//1018. 锤子剪刀布 (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：


现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，
即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，
第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，
分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B



#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int jiawin = 0;
    int yiwin = 0;
    int jia[3] = {0};
    int yi[3] = {0};
    for (int i = 0; i < n; i++) {
        char s, t;
        cin >> s >> t;
        if (s != t) {
            if (s == 'B') {
                if (t == 'C') {
                    jiawin++;
                    jia[0]++;
                }
                if (t == 'J') {
                    yiwin++;
                    yi[2]++;
                }
            }
            if (s == 'C') {
                if (t == 'B') {
                    yiwin++;
                    yi[0]++;
                }
                if (t == 'J') {
                    jiawin++;
                    jia[1]++;
                }
            }
            if (s == 'J') {
                if (t == 'B') {
                    jiawin++;
                    jia[2]++;
                }
                if (t == 'C') {
                    yiwin++;
                    yi[1]++;
                }
            }
        }
    }
    cout << jiawin << " " << n - jiawin - yiwin << " " << yiwin << endl;
    cout << yiwin << " " << n - jiawin - yiwin << " " << jiawin << endl;
    int maxjia = 0;
    if (jia[0] < jia[1]) {
        maxjia = 1;
        if (jia[1] < jia[2])
            maxjia = 2;
    }
    else {
        if (jia[0] < jia[2]) {
            maxjia = 2;
        }
    }
    int maxyi = 0;
    if (yi[0] < yi[1]) {
        maxyi = 1;
        if (yi[1] < yi[2])
            maxyi = 2;
    }
    else {
        if (yi[0] < yi[2]) {
            maxyi = 2;
        }
    }
    if (maxjia == 0) cout << "B";
    if (maxjia == 1) cout << "C";
    if (maxjia == 2) cout << "J";
    cout << " ";
    if (maxyi == 0) cout << "B";
    if (maxyi == 1) cout << "C";
    if (maxyi == 2) cout << "J";
    return 0;
}