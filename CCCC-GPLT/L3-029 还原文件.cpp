#include <bits/stdc++.h>
using namespace std;
int n, m, k, t, flag1, flag2;
int h[100001], vis[101];
vector<int> Ans, frag[101];
void DFS (int p) {
    if ((int)Ans.size() == m) {
        flag1 = 1;
        for (int i = 0; i < m; i++) {
            if (i) cout << ' ';
            cout << Ans[i];
        }
    }
    if (flag1) return;
    for (int i = 1; i <= m; i++) {
        if (vis[i]) continue;
        flag2= 0;
        for (int j = 0; j < (int)frag[i].size(); j++) {
            if (frag[i][j] != h[p + j]) {
                flag2 = 1;
                break;
            }
        }
        if (flag2) continue;
        Ans.push_back(i);
        vis[i] = 1;
        DFS(p + (int)frag[i].size() - 1);
        vis[i] = 0;
        Ans.pop_back();
    }
};
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
    cin >> m;
    for (int i = 1; i<= m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            frag[i].push_back(t);
        }
    }
    DFS(0);
    return 0;
}