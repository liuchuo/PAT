1037. 在霍格沃茨找零钱（20）
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 
就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，
二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，
你的任务是写一个程序来计算他应该被找的零钱。
输入格式：
输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 10^7]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。
输出格式：
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。
输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1
输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1

#include <iostream>
using namespace std;
int main() {
    int a, b ,c;
    int m, n, t;
    scanf("%d.%d.%d",&a, &b, &c);
    scanf("%d.%d.%d",&m, &n, &t);
    int flag;
    if (a > m ||(a == m && b > n) ||(a == m && b == n && c > t))
        flag = 0;
    else
        flag = 1;

    int x, y, z;
    if (flag == 1) {
        if (t >= c) {
            z = t - c;
        } else {
            z = t + 29 - c;
            n = n - 1;
        }
        if (n >= b) {
            y = n - b;
        } else {
            y = n + 17 - b;
            m = m - 1;
        }
        x = m - a;
        cout << x << "." << y << "." << z;
    } else {
        if (c >= t) {
            z = c - t;
        } else {
            z = c + 29 - t;
            b = b - 1;
        }
        if (b >= n) {
            y = b - n;
        } else {
            y = b + 17 - n;
            a = a - 1;
        }
        x = a - m;
        cout << "-" << x << "." << y << "." << z;
    }
    return 0;
}
