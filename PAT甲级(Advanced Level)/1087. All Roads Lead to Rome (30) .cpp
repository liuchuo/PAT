1087. All Roads Lead to Rome (30)
Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<=N<=200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N-1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format "City1 City2 Cost". Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.
Output Specification:
For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommended. If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.
Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommended route. Then in the next line, you are supposed to print the route in the format "City1->City2->...->ROM".
Sample Input:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
Sample Output:
3 3 195 97
HZH->PRS->ROM

分析：Dijkstra+DFS。Dijkstra算出所有最短路径的路线pre二维数组，DFS求最大happiness的路径path，并求出路径条数，最大happiness，最大average。
注意：average是除去起点的average。城市名称可以用m存储字符串所对应的数字，用m2存储数字对应的字符串。

#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
const int inf = 999999999;
int e[205][205], weight[205], dis[205];
bool visit[205];
vector<int> pre[205], temppath, path;
map<string, int> m;
map<int, string> m2;
int maxvalue = 0, mindepth, cntpath = 0;
double maxavg;
void dfs(int v) {
    temppath.push_back(v);
    if(v == 1) {
        int value = 0;
        for(int i = 0; i < temppath.size(); i++) {
            value += weight[temppath[i]];
        }
        double tempavg = 1.0 * value / (temppath.size() - 1);
        if(value > maxvalue) {
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;
        } else if(value == maxvalue && tempavg > maxavg) {
            maxavg = tempavg;
            path = temppath;
        }
        temppath.pop_back();
        cntpath++;
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 205 * 205, inf);
    fill(dis, dis + 205, inf);
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;
    m[s] = 1;
    m2[1] = s;
    for(int i = 1; i < n; i++) {
        cin >> s >> weight[i+1];
        m[s] = i+1;
        m2[i+1] = s;
    }
    string sa, sb;
    int temp;
    for(int i = 0; i < k; i++) {
        cin >> sa >> sb >> temp;
        e[m[sa]][m[sb]] = temp;
        e[m[sb]][m[sa]] = temp;
    }
    dis[1] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 1; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 1; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    int rom = m["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", cntpath, dis[rom], maxvalue, (int)maxavg);
    for(int i = path.size() - 1; i >= 1; i--) {
        cout << m2[path[i]] << "->";
    }
    cout << "ROM";
    return 0;
}
