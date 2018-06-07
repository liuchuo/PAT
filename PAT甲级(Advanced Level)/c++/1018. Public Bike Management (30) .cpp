1018. Public Bike Management (30)
There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.
The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.
When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.
Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:
1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.
2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.
Input Specification:
Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0->S1->...->Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.
Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.
Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0
题目大意：每个自行车车站的最大容量为一个偶数cmax，如果一个车站里面自行车的数量恰好为cmax / 2，那么称处于完美状态。如果一个车展容量是满的或者空的，控制中心（处于结点0处）就会携带或者从路上手机一定数量的自行车前往该车站，一路上会让所有的车展沿途都达到完美。现在给出cmax，车站的数量n，问题车站sp，m条边，还有距离，求最短路径。如果最短路径有多个，求能带的最少的自行车数目的那条。如果还是有很多条不同的路，那么就找一个从车站带回的自行车数目最少的。带回的时候是不调整的
分析：Dijkstra + DFS。如果只有Dijkstra是不可以的，因为minNeed和minBack在路径上的传递不满足最优子结构，不是简单的相加的过程，只有在所有路径都确定了之后才能区选择最小的need和最小的back
Dijkstra求最短路径，dfs求minNeed和minBack和path，dfs的时候模拟一遍需要调整的过程，求出最后得到的need和back，与minNeed和minBack比较然后根据情况更新path，最后输出minNeed path 和 minBack，记得path是从最后一个结点一直到第一个结点的，所以要倒着输出~

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 99999999;
int cmax, n, sp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510], path, temppath;
void dfs(int v) {
    if(v == 0) {
        temppath.push_back(v);
        int need = 0, back = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            if(weight[id] > 0) {
                back += weight[id];
            } else {
                if(back > (0 - weight[id])) {
                    back += weight[id];
                } else {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    temppath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - cmax / 2;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    dis[0] = 0;
    for(int i = 0; i <= n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(sp);
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
}