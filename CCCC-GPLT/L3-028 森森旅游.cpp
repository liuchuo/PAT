#include <bits/stdc++.h>
using namespace std;
#define pil pair<int, long long>
struct node {
    int id;
    long long dis;
    friend int operator < (const node &a, const node &b) {
        return a.dis > b.dis;
    }
};
int n, m, q, u, v, xi, vis1[100005], vis2[100005];
long long c, d, w, ai, huan[100005], cashD[100005], voucherD[100005], tran[100005];
vector<pil> cashE[100005], voucherE[100005];
multiset<long long> minCost;
priority_queue<node> Q;
void Dijskra (int s, vector<pil> E[], long long Dis[], int Vis[]) {
    fill (Dis + 1, Dis + n + 1, LLONG_MAX);
    Dis[s] = 0;
    Q.push(node{s, 0});
    while (!Q.empty()) {
        int now = Q.top().id;
        Q.pop();
        if (Vis[now]) continue;
        Vis[now] = 1;
        for (int i = 0; i < (int)E[now].size(); ++i) {
            v = E[now][i].first;
            w = E[now][i].second;
            if (Dis[v] > Dis[now] + w) {
                Dis[v] = Dis[now] + w;
                Q.push(node{v, Dis[v]});
            }
        }
    } 
}
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%lld%lld", &u, &v, &c, &d);
        cashE[u].push_back({v, c});
        voucherE[v].push_back({u, d});
    }
    for (int i = 1; i <= n; i++) scanf("%lld", &huan[i]);
    Dijskra(1, cashE, cashD, vis1);
    Dijskra(n, voucherE, voucherD, vis2);
    for (int i = 1; i <= n; i++) {
        if (cashD[i] == LLONG_MAX || voucherD[i] == LLONG_MAX) continue;
        minCost.insert(tran[i] = cashD[i] + (voucherD[i]+huan[i]-1) / huan[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d%lld", &xi, &ai);
        if (!tran[xi] || huan[xi] == ai) {
            printf("%lld\n", *minCost.begin());
        } else {
            minCost.erase(minCost.find(tran[xi]));
            huan[xi] = ai;
            minCost.insert(tran[xi] = cashD[xi]+(voucherD[xi]+huan[xi]-1)/huan[xi]);
            printf("%lld\n", *minCost.begin());
        }
    }
    return 0;
}