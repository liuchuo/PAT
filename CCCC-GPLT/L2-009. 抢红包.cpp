L2-009. 抢红包
没有人没抢过红包吧…… 这里给出N个人之间互相发红包、抢红包的记录，请你统计一下他们抢红包的收获。

输入格式：

输入第一行给出一个正整数N（<= 104），即参与发红包和抢红包的总人数，则这些人从1到N编号。随后N行，第i行给出编号为i的人发红包的记录，格式如下：

K N1 P1 ... NK PK

其中K（0 <= K <= 20）是发出去的红包个数，Ni是抢到红包的人的编号，Pi（> 0）是其抢到的红包金额（以分为单位）。注意：对于同一个人发出的红包，每人最多只能抢1次，不能重复抢。

输出格式：

按照收入金额从高到低的递减顺序输出每个人的编号和收入金额（以元为单位，输出小数点后2位）。每个人的信息占一行，两数字间有1个空格。如果收入金额有并列，则按抢到红包的个数递减输出；如果还有并列，则按个人编号递增输出。

输入样例：
10
3 2 22 10 58 8 125
5 1 345 3 211 5 233 7 13 8 101
1 7 8800
2 1 1000 2 1000
2 4 250 10 320
6 5 11 9 22 8 33 7 44 10 55 4 2
1 3 8800
2 1 23 2 123
1 8 250
4 2 121 4 516 7 112 9 10
输出样例：
1 11.63
2 3.63
8 3.63
3 2.11
7 1.69
6 -1.67
9 -2.18
10 -3.26
5 -3.26
4 -12.32

分析：用结构体存储下每一个结点的id、收入、收到红包的总数，然后进行排序后输出

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int id, total, getnum;
};
bool cmp1(node a, node b) {
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.getnum != b.getnum)
        return a.getnum > b.getnum;
    else
        return a.id < b.id;
}
int main() {
    int n, k, a, b;
    scanf("%d", &n);
    vector<node> v(n + 1);
    for(int i = 1; i <= n; i++) {
        v[i].id = i;
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d %d", &a, &b);
            v[a].total += b;
            v[a].getnum++;
            v[i].total -= b;
        }
    }
    sort(v.begin()+1, v.end(), cmp1);
    for(int i = 1; i <= n; i++) {
        double temp = (double)(v[i].total * 1.0 / 100);
        printf("%d %.2f\n", v[i].id, temp);
    }
    return 0;
}
