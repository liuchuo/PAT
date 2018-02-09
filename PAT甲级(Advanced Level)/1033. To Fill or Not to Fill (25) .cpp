1033. To Fill or Not to Fill (25)
With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.
Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive numbers: Cmax (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; Davg (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: Pi, the unit gas price, and Di (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.
Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00

分析：贪心算法。
0.假设增加一个目的地处的加油站，距离为目的地的距离，价格为0，考虑从0距离开始能否到达最后一个加油站的问题
1.因为先开始没有油，所以如果所有的加油站距离都没有等于0的，那么说明车哪也去不了，直接输出并return
2.将加油站按照距离dis从小到大排序
3.先去第一个加油站，设置变量nowdis表示当前所在的距离，maxdis是能够到达的最大距离，nowprice是当前的站点的价格，totalPrice是总的价格。
贪心思想：
0.寻找比自己距离远的，到能够到达的最大距离之间的加油站，看他们的油价。如果找到了更低价格的油价，就加油到刚好能到达那个加油站的距离的油，然后去那个更低价格的加油站（有更低的我一分都不想多花在别的距离上，只加到刚好满足更低价格的加油站的距离就行，那样以后的路程我就可以以更低的价格行驶啦）
1.如果找不到更低的，就找尽可能低的油价的加油站，在当前加油站加满油之后过去。因为想要让路程上使用的尽可能是低价的油，既然没有比当前更低价格的了，就让油箱加到最大值，这样能保证利益最大化，保证最大的距离使用的是便宜的油。

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 99999999;
struct station {
    double price, dis;
};
bool cmp1(station a, station b) {
    return a.dis < b.dis;
}
int main() {
    double cmax, d, davg;
    int n;
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    vector<station> sta(n + 1);
    sta[0].price = 0.0;
    sta[0].dis = d;
    for(int i = 1; i <= n; i++) {
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    }
    sort(sta.begin(), sta.end(), cmp1);
    double nowdis = 0.0,  maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;
    if(sta[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    } else {
        nowprice = sta[0].price;
    }
    while(nowdis < d) {
        maxdis = nowdis + cmax * davg;
        double minPriceDis = 0, minPrice = inf;
        int flag = 0;
        for(int i = 1; i <= n && sta[i].dis <= maxdis; i++) {
            if(sta[i].dis <= nowdis) continue;
            if(sta[i].price < nowprice) {
                totalPrice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;
                leftdis = 0.0;
                nowprice = sta[i].price;
                nowdis = sta[i].dis;
                flag = 1;
                break;
            }
            if(sta[i].price < minPrice) {
                minPrice = sta[i].price;
                minPriceDis = sta[i].dis;
            }
        }
        if(flag == 0 && minPrice != inf) {
            totalPrice += (nowprice * (cmax - leftdis / davg));
            leftdis = cmax * davg - (minPriceDis - nowdis);
            nowprice = minPrice;
            nowdis = minPriceDis;

        }
        if(flag == 0 && minPrice == inf) {
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalPrice);
    return 0;
}