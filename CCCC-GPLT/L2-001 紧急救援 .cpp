#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, c1, c2;
int dis[510], weight[510], e[510][510], num[510], w[510], pre[510];
bool visit[510];
const int inf = 99999999;
void printPath(int v) {
    if(v == c1) {
        printf("%d", v);
        return ;
    }
    printPath(pre[v]);
    printf(" %d", v);
}
int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    int a, b, c;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = c;
        e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
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
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                    pre[v] = u;
                } else if(dis[u] + e[u][v] == dis[v]) {
                    num[v] = num[v] + num[u];
                    if(w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
    printf("%d %d\n", num[c2], w[c2]);
    printPath(c2);
    return 0;
}