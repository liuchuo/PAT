#include <bits/stdc++.h>
using namespace std;
int N, M, K, u, v, w, n, flag, cost, Ansnum, Ansid, Anscost = INT_MAX, Edge[201][201], Path[202], Has[201];
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        Edge[u][v] = Edge[v][u] = w;
    }
    cin >> K;
    for (int i = 1; i <= K; i++) {
        fill(Has, Has + N + 1, 0);
        Path[N + 1] = flag = cost = 0;
        cin >> n;
        for (int j = 1; j <= n; j++){
            cin >> Path[j];
            if(Has[Path[j]]) Has[0] = 1;
            Has[Path[j]] = 1;
        }
        if (Has[0] || n != N) continue;
        for (int j = 1; j <= n + 1; j++) {
            if (Edge[Path[j-1]][Path[j]] == 0) {
                flag = 1;
                break;
            }
            cost += Edge[Path[j - 1]][Path[j]];
        }
        if (!flag) {
            Ansnum++;
            if(cost < Anscost) Ansid = i, Anscost = cost;
        }
    }
    cout << Ansnum << '\n' << Ansid << ' ' << Anscost;
    return 0;
}