L1-006. 连续因子
一个正整数N的因子中可能存在若干连续的数字。例如630可以分解为3*5*6*7，其中5、6、7就是3个连续的数字。给定任一正整数N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：

输入在一行中给出一个正整数N（1<N<231）。

输出格式：

首先在第1行输出最长连续因子的个数；然后在第2行中按“因子1*因子2*……*因子k”的格式输出最小的连续因子序列，其中因子按递增顺序输出，1不算在内。

输入样例：
630
输出样例：
3
5*6*7


#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int max = sqrt(n);
    for(int len = 12; len >= 1; len--) {
        for(int start = 2; start <= max; start++) {
            long long int ans = 1;
            for(int i = start; i - start <= len - 1; i++) {
                ans *= i;
            }
            if(n % ans == 0) {
                printf("%d\n%d", len, start);
                for(int i = start + 1; i - start <= len - 1; i++) {
                    printf("*%d", i);
                }
                return 0;
            }
        }
    }
    printf("1\n%d", n);
    return 0;
}