#include <bits/stdc++.h>
using namespace std;
int n, m, s, c;
queue<char> Q[1005];
stack<char> St;
int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        for (int j = 0; j < m; j++) Q[i].push(t[j]);
    }
    while (cin >> c) {
        if (c == -1) break;
        if (c == 0) {
            if (St.empty()) continue;
            cout << St.top();
            St.pop();
        } else {
            if (Q[c].empty()) continue;
            if (St.size() == s) {
                cout << St.top();
                St.pop();
            }
            St.push(Q[c].front());
            Q[c].pop();
        }
    }
    return 0;
} 