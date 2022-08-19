#include <bits/stdc++.h>
using namespace std;
const int Mx = 1e9;
int N, M, K, Q, from, to, dis, Ter[201], Edge[201][201];
map<int, set<int>> Station;
map<int, set<int>> Ans;
void DFS(int Start, int Now) {
    for (auto it : Station[Now]) {
        if (Ans[Start].count(it)) continue;
        Ans[Start].insert(it);
        DFS(Start, it);
    }
}
int main() {
    for (int i = 1; i <= 200; i++)
        for (int j = 1; j <= 200; j++)
            Edge[i][j] = Mx;
    scanf("%d %d %d", &N, &M, &K);
    while (M--) {
        scanf("%d", &from);
        Ter[from] = 1;
        while (1) {
            scanf("%d %d", &dis, &to);
            Edge[from][to] = Edge[to][from] = min(Edge[from][to], dis);
            from = to;
            if (getchar() == '\n') break;
        }
        Ter[to] = 1;
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) 
                if (i != j) Edge[i][j] = min(Edge[i][j], Edge[i][k] + Edge[k][j]);
    for (int i = 1; i <= N; i++) {
        map<int, int> Fur_Dis;
        Ans[i].insert(i);
        for (int j = 1; j <= N; j++) {
            if (Edge[i][j] != Mx) {
                if (Ter[j] == 1) Station[i].insert(j);
                if (Edge[i][j] > Fur_Dis[Edge[i][j] / K]) Fur_Dis[Edge[i][j] / K] = Edge[i][j];
            }
        }
        for (int j = 1; j <= N; j++)
            if (Edge[i][j] == Fur_Dis[Edge[i][j] / K]) Station[i].insert(j);
    }
    for (int i = 1; i <= N; i++) DFS(i, i);
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &from);
        for (auto it : Ans[from]) 
            printf("%d%c", it, (it != *Ans[from].rbegin()) ? ' ' : '\n');
    }
    return 0;
}