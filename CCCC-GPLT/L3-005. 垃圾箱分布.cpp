L3-005. 垃圾箱分布
大家倒垃圾的时候，都希望垃圾箱距离自己比较近，但是谁都不愿意守着垃圾箱住。所以垃圾箱的位置必须选在到所有居民点的最短距离最长的地方，同时还要保证每个居民点都在距离它一个不太远的范围内。

现给定一个居民区的地图，以及若干垃圾箱的候选地点，请你推荐最合适的地点。如果解不唯一，则输出到所有居民点的平均距离最短的那个解。如果这样的解还是不唯一，则输出编号最小的地点。

输入格式：

输入第一行给出4个正整数：N（<= 103）是居民点的个数；M（<= 10）是垃圾箱候选地点的个数；K（<= 104）是居民点和垃圾箱候选地点之间的道路的条数；DS是居民点与垃圾箱之间不能超过的最大距离。所有的居民点从1到N编号，所有的垃圾箱候选地点从G1到GM编号。

随后K行，每行按下列格式描述一条道路：
P1 P2 Dist
其中P1和P2是道路两端点的编号，端点可以是居民点，也可以是垃圾箱候选点。Dist是道路的长度，是一个正整数。

输出格式：

首先在第一行输出最佳候选地点的编号。然后在第二行输出该地点到所有居民点的最小距离和平均距离。数字间以空格分隔，保留小数点后1位。如果解不存在，则输出“No Solution”。

输入样例1：
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
输出样例1：
G1
2.0 3.3
输入样例2：
2 1 2 10
1 G1 9
2 G1 20
输出样例2：
No Solution

题目大意：从m个垃圾站里面选取1个站点，让他离居民区的最近的人最远，并且没有超出服务范围ds之内。如果有很多个最远的垃圾站，输出距离所有居民区距离平均值最小的那个。如果平均值还是一样，就输出按照顺序排列垃圾站编号最小的那个、
分析：
因为垃圾站之间也是彼此有路连接的，所以最短路径计算的时候也要把垃圾站算上。所以我们就是堆n+m个点进行Dijkstra计算最短路径。要求计算出1~m号垃圾站距离其他站点的最短路径。这时候可以遍历dis数组，如果dis存在一个距离大于服务范围ds的距离，那么我们就舍弃这个垃圾站。取最最短的路径，这就是距离它最近的垃圾站mindis。如果mindis > ansdis，就是说找到了一个距离居民最小距离的垃圾站是更远的，那就选这个垃圾站，更新ansid为它的id。最后输出
对于垃圾站的字符串编号的处理：如果最近居民区最大的值没有变化但是找到了一个更小的平均距离，那就选这个。我们可以根据输入的是G还是数字，如果是数字就令编号为他自己，如果是G开头的，编号设为n+G后面的数字。

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int inf = 999999999;
int n, m, k, ds, station;
int e[1020][1020], dis[1020];
bool visit[1020];
int main() {
    fill(e[0], e[0] + 1020 * 1020, inf);
    fill(dis, dis + 1020, inf);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    for(int i = 0; i < k; i++) {
        int tempdis;
        string s, t;
        cin >> s >> t >> tempdis;
        int a, b;
        if(s[0] == 'G') {
            s = s.substr(1);
            a = n + stoi(s);
        } else {
            a = stoi(s);
        }
        if(t[0] == 'G') {
            t = t.substr(1);
            b = n + stoi(t);
        } else {
            b = stoi(t);
        }
        e[a][b] = tempdis;
        e[b][a] = tempdis;
    }
    int ansid = -1;
    double ansdis = -1, ansaver = inf;
    for(int index = n + 1; index <= n + m; index++) {
        double mindis = inf, aver = 0;
        fill(dis, dis + 1020, inf);
        fill(visit, visit + 1020, false);
        dis[index] = 0;
        for(int i = 0; i < n + m; i++) {
            int u = -1, minn = inf;
            for(int j = 1; j <= n + m; j++) {
                if(visit[j] == false && dis[j] < minn) {
                    u = j;
                    minn = dis[j];
                }
            }
            if(u == -1) break;
            visit[u] = true;
            for(int v = 1; v <= n + m; v++) {
                if(visit[v] == false && dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
        for(int i = 1; i <= n; i++) {
            if(dis[i] > ds) {
                mindis = -1;
                break;
            }
            if(dis[i] < mindis) mindis = dis[i];
            aver += 1.0 * dis[i];
        }
        if(mindis == -1) continue;
        aver = aver / n;
        if(mindis > ansdis) {
            ansid = index;
            ansdis = mindis;
            ansaver = aver;
        } else if(mindis == ansdis && aver < ansaver) {
            ansid = index;
            ansaver = aver;
        }
    }
    if(ansid == -1)
        printf("No Solution");
    else {
        printf("G%d\n", ansid - n);
        printf("%.1f %.1f", ansdis, ansaver);
    }
    return 0;
}