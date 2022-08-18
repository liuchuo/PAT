#include <bits/stdc++.h>
using namespace std;
#define pii pair<int ,int>
int n, k, t, S, Long = 0,  ans, in[10005], pa[10005];
vector<int> F, Edge[10005];
queue<pii> Q;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            in[t]++;
            pa[t] = i;
            Edge[i].push_back(t);
        }
        sort(Edge[i].begin(), Edge[i].end());
    }
    for (int i = 0; i < n; i++) if (in[i] == 0) S = i;
    while(!Q.empty()) Q.pop();
    Q.push({S, 1});
    while (!Q.empty()) {
        int now = Q.front().first, D = Q.front().second;
        Q.pop();
        if (D > Long) {
            Long = D;
            ans = now;
        }
        for (auto nex : Edge[now]) Q.push({nex, D + 1});
    }
    cout << Long << '\n';
    while (ans != S) {
        F.push_back(ans);
        ans = pa[ans];
    }
    F.push_back(S);
    for (int i = F.size() - 1; ~i; --i) {
        cout << F[i];
        if (i != 0) cout << ' ';
    }
    return 0;
} 