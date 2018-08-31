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