L3-007. 天梯地图
本题要求你实现一个天梯赛专属在线地图，队员输入自己学校所在地和赛场地点后，该地图应该推荐两条路线：一条是最快到达路线；一条是最短距离的路线。题目保证对任意的查询请求，地图上都至少存在一条可达路线。

输入格式：

输入在第一行给出两个正整数N（2 <= N <=500）和M，分别为地图中所有标记地点的个数和连接地点的道路条数。随后M行，每行按如下格式给出一条道路的信息：

V1 V2 one-way length time

其中V1和V2是道路的两个端点的编号（从0到N-1）；如果该道路是从V1到V2的单行线，则one-way为1，否则为0；length是道路的长度；time是通过该路所需要的时间。最后给出一对起点和终点的编号。

输出格式：

首先按下列格式输出最快到达的时间T和用节点编号表示的路线：

Time = T: 起点 => 节点1 => ... => 终点

然后在下一行按下列格式输出最短距离D和用节点编号表示的路线：

Distance = D: 起点 => 节点1 => ... => 终点

如果最快到达路线不唯一，则输出几条最快路线中最短的那条，题目保证这条路线是唯一的。而如果最短距离的路线不唯一，则输出途径节点数最少的那条，题目保证这条路线是唯一的。

如果这两条路线是完全一样的，则按下列格式输出：

Time = T; Distance = D: 起点 => 节点1 => ... => 终点

输入样例1：
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
5 4 0 2 3
5 9 1 1 4
0 6 0 1 1
7 3 1 1 2
8 3 1 1 2
2 5 0 2 2
2 1 1 1 1
1 5 0 1 3
1 4 0 1 1
9 7 1 1 3
3 1 0 2 5
6 3 1 2 1
5 3
输出样例1：
Time = 6: 5 => 4 => 8 => 3
Distance = 3: 5 => 1 => 3
输入样例2:
7 9
0 4 1 1 1
1 6 1 3 1
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 3 1
3 2 1 2 1
4 5 0 2 2
6 5 1 2 1
3 5
输出样例2:
Time = 3; Distance = 4: 3 => 2 => 5

分析：用两个Dijkstra + DFS。一个求最快路径（如果相同求路径的那条），一个求最短路径（如果相同求结点数最小的那条）~~~求最快路径可以直接在Dijkstra里面求前驱结点Timepre数组~~~求最短路径因为要求结点数最小的那条，所以要用dispre的二维数组存储所有结点的最短路径，然后用DFS求出满足条件的结点数最小的那条~~~~
注意：
1.一开始最后一个测试用例“答案错误”，后来发现是自己在求最短路径（第二个答案distance）的时候忘记了temppath每一次深搜结束后的pop_back();
2.如果直接使用DFS的话，会导致最后一个测试用例“运行超时”~~~

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 999999999;
int dis[510], Time[510], e[510][510], w[510][510], Timepre[510], weight[510];
bool visit[510];
vector<int> Timepath, dispath, temppath, dispre[510];
int st, fin, minnode = inf;
void dfsTimepath(int v) {
    Timepath.push_back(v);
    if(v == st) {
        return ;
    }
    dfsTimepath(Timepre[v]);
}

void dfsdispath(int v) {
    temppath.push_back(v);
    if(v == st) {
        if(temppath.size() < minnode) {
            minnode = temppath.size();
            dispath = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < dispre[v].size(); i++) {
        dfsdispath(dispre[v][i]);
    }
    temppath.pop_back();
}
int main() {
    fill(dis, dis + 510, inf);
    fill(Time, Time + 510, inf);
    fill(weight, weight + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, flag, len, t;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if(flag != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    scanf("%d %d", &st, &fin);

    Time[st] = 0;
    for(int i = 0; i < n; i++) {
        Timepre[i] = i;
    }
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && Time[j] < minn) {
                u = j;
                minn = Time[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && w[u][v] != inf) {
                if(w[u][v] + Time[u] < Time[v]) {
                    Time[v] = w[u][v] + Time[u];
                    Timepre[v] = u;
                    weight[v] = weight[u] + e[u][v];
                } else if(w[u][v] + Time[u] == Time[v] && weight[v] > weight[u] + e[u][v]) {
                    weight[v] = weight[u] + e[u][v];
                    Timepre[v] = u;
                }
            }
        }
    }
    dfsTimepath(fin);

    fill(visit, visit + 510, false);
    dis[st] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && minn > dis[j]) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    dispre[v].clear();
                    dispre[v].push_back(u);
                } else if(e[u][v] + dis[u] == dis[v]) {
                    dispre[v].push_back(u);
                }
            }
        }
    }
    dfsdispath(fin);
    printf("Time = %d", Time[fin]);
    if(dispath == Timepath) {
        printf("; Distance = %d: ", dis[fin]);
    } else {
        printf(": ");
        for(int i = Timepath.size() - 1; i >= 0; i--) {
            printf("%d", Timepath[i]);
            if(i != 0) printf(" => ");
        }
        printf("\n");
        printf("Distance = %d: ", dis[fin]);
    }
    for(int i = dispath.size() - 1; i >= 0; i--) {
        printf("%d", dispath[i]);
        if(i != 0) printf(" => ");
    }
    return 0;
}