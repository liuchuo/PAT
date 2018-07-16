1072. Gas Station (30)
A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.
Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.
Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive integers: N (<= 103), the total number of houses; M (<= 10), the total number of the candidate locations for the gas stations; K (<= 104), the number of roads connecting the houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.
Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.
Output Specification:
For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output “No Solution”.
Sample Input 1:
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
Sample Output 1:
G1
2.0 3.3
Sample Input 2:
2 1 2 10
1 G1 9
2 G1 20
Sample Output 2:
No Solution

题目大意：从m个加油站里面选取1个站点，让他离居民区的最近的人最远，并且没有超出服务范围ds之内。如果有很多个最远的加油站，输出距离所有居民区距离平均值最小的那个。如果平均值还是一样，就输出按照顺序排列加油站编号最小的那个、
分析：
因为加油站之间也是彼此有路连接的，所以最短路径计算的时候也要把加油站算上。所以我们就是堆n+m个点进行Dijkstra计算最短路径。要求计算出1~m号加油站距离其他站点的最短路径。这时候可以遍历dis数组，如果dis存在一个距离大于服务范围ds的距离，那么我们就舍弃这个加油站。取最最短的路径，这就是距离它最近的加油站mindis。如果mindis > ansdis，就是说找到了一个距离居民最小距离的加油站是更远的，那就选这个加油站，更新ansid为它的id。最后输出
对于加油站的字符串编号的处理：如果最近居民区最大的值没有变化但是找到了一个更小的平均距离，那就选这个。我们可以根据输入的是G还是数字，如果是数字就令编号为他自己，如果是G开头的，编号设为n+G后面的数字。
Update：Github用户littlesevenmo提出需要添加输入判断，题目中并没有说明两点之间最多只有一条路。也就是说，有可能两点之间有多条路，因此需要添加判断，只存储距离最短的路。另外，也有可能会出现 G1 G1 9999这样的测试数据，因此，自身与自身之间的距离要初始化为0。完善后的代码如下：

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int inf = 999999999;
int n, m, k, ds, station;
int e[1020][1020], dis[1020];
bool visit[1020];
int main() {
    fill(e[0], e[0] + 1020 * 1020, inf);
    for (int i = 0; i < 1020; i++)
        e[i][i] = 0;
    fill(dis, dis + 1020, inf);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    string s, t;
    for (int i = 0; i < k; i++) {
        int tempdis;
        cin >> s >> t >> tempdis;
        int a, b;
        if (s[0] == 'G') {
            s = s.substr(1);
            a = n + stoi(s);
        } else {
            a = stoi(s);
        }
        if (t[0] == 'G') {
            t = t.substr(1);
            b = n + stoi(t);
        } else {
            b = stoi(t);
        }
        e[a][b] = e[b][a] = min(tempdis, e[a][b]);
    }
    int ansid = -1;
    double ansdis = -1, ansaver = inf;
    for (int index = n + 1; index <= n + m; index++) {
        double mindis = inf, aver = 0;
        fill(dis, dis + 1020, inf);
        fill(visit, visit + 1020, false);
        dis[index] = 0;
        for (int i = 0; i < n + m; i++) {
            int u = -1, minn = inf;
            for (int j = 1; j <= n + m; j++) {
                if (visit[j] == false && dis[j] < minn) {
                    u = j;
                    minn = dis[j];
                }
            }
            if (u == -1) break;
            visit[u] = true;
            for (int v = 1; v <= n + m; v++) {
                if (visit[v] == false && dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dis[i] > ds) {
                mindis = -1;
                break;
            }
            if (dis[i] < mindis) mindis = dis[i];
            aver += 1.0 * dis[i];
        }
        if (mindis == -1) continue;
        aver = aver / n;
        if (mindis > ansdis) {
            ansid = index;
            ansdis = mindis;
            ansaver = aver;
        } else if (mindis == ansdis && aver < ansaver) {
            ansid = index;
            ansaver = aver;
        }
    }
    if (ansid == -1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f", ansid - n, ansdis, ansaver);
    return 0;
}