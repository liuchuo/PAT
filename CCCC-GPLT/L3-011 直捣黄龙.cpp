#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, dis;
    bool friend operator < (const node &a, const node &b) {
        return a.dis > b.dis;
    }
};
int n, k, s, t, cnt, d, num[205], Num[205], path[205], Dis[205], vis[205], sum[205], liberation[205];
map<string, int> ntoi;
map<int, string> iton;
vector<pair<int, int>> E[205];
vector<int> ans;
string S, T, u, v;
void Dijskra() {
    fill(Dis, Dis + 205, 1e9);
    Dis[s] = 0;
    sum[s] = 1;
    priority_queue<node> Q;
    Q.push(node{s, 0});
    while (!Q.empty()) {
        int Now = Q.top().id, D = Q.top().dis;
        Q.pop();
        if (vis[Now]) continue;
        vis[Now] = 1;
        for (auto it : E[Now]) {
            int V = it.first, DIS = it.second;
            if (Dis[V] > D + DIS) {
                Num[V] = Num[Now] + num[V];
                sum[V] = sum[Now];
                liberation[V] = liberation[Now] + 1;
                Dis[V] = D + DIS;
                Q.push(node{V, Dis[V]});
                path[V] = Now;
            } else if (Dis[V] == D + DIS) {
                sum[V] += sum[Now];
                if (liberation[V] < liberation[Now] + 1) {
                    liberation[V] = liberation[Now] + 1;
                    Num[V] = Num[Now] + num[V];
                    Q.push(node{V, Dis[V]});
                    path[V] = Now;
                } else if (liberation[V] == liberation[Now] + 1) {
                    if (Num[V] < Num[Now] + num[V]) {
                        Num[V] = Num[Now] + num[V];
                        Q.push(node{V, Dis[V]});
                        path[V] = Now;
                    }
                }
                
            }
        }
    }
}
int main() {
    cin >> n >> k >> S >> T;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> d;
        ntoi[u] = ++cnt;
        iton[cnt] = u;
        num[cnt] = d;
    }
    ntoi[S] = 0, iton[0] = S, t = ntoi[T];
    for (int i = 0; i < k; i++) {
        cin >> u >> v >> d;
        E[ntoi[u]].push_back({ntoi[v], d});
        E[ntoi[v]].push_back({ntoi[u], d});
    }
    Dijskra();
    d = t;
    while(d) {
        ans.push_back(d);
        d = path[d];
    }
    cout << iton[0];
    for (int i = ans.size() - 1; i >= 0; i--) cout << "->" << iton[ans[i]];
    cout << '\n' << sum[t] << ' ' << Dis[t] << ' ' << Num[t] << '\n';
    return 0;
}