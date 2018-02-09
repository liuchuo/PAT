1030. Travel Plan (30)
A traveler‘s map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40
题目大意：求起点到终点的最短路径最短距离和花费，要求首先路径最短，其次花费最少，要输出完整路径。
分析：Dijksta + DFS。 Dijkstra记录路径pre数组，然后用dfs求最短的一条mincost以及它的路径path，最后输出path数组和mincost
注意路径path因为是从末端一直压入push_back到path里面的，所以要输出路径的时候倒着输出

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, s, d;
int e[510][510], dis[510], cost[510][510];
vector<int> pre[510];
bool visit[510];
const int inf = 99999999;
vector<int> path, temppath;
int mincost = inf;
void dfs(int v) {
    if(v == s) {
        temppath.push_back(v);
        int tempcost = 0;
        for(int i = temppath.size() - 1; i > 0; i--) {
            int id = temppath[i], nextid = temppath[i-1];
            tempcost += cost[id][nextid];
        }
        if(tempcost < mincost) {
            mincost = tempcost;
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
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
        scanf("%d", &cost[a][b]);
        cost[b][a] = cost[a][b];
    }
    pre[s].push_back(s);
    dis[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(d);
    for(int i = path.size() - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("%d %d", dis[d], mincost);
    return 0;
}