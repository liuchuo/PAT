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