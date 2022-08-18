#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int N, K, D, one, vis[100001];
vector<int> Edge[100001];
queue<int> Q;
int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> K;
        while(K--) {
            cin >> D;
            Edge[D].push_back(i);
            Edge[i].push_back(D);
        }
    }
    Q.push(1);
    vis[1] = 1;
    while(!Q.empty()) {
        one = Q.front();
        Q.pop();
        for (auto v:Edge[one]) {
            if (vis[v]) continue;
            vis[v] = 1;
            Q.push(v);
        }
    }
    cout << one;
    return 0;
}