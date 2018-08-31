#include <cstdio>
#include <vector>
using namespace std;
int n, kn;
vector<int> v;
vector<vector<int>> graph;
int isConnected() {
    int pre = v[0];
    for (int i = 1; i < kn; i++) {
        if (graph[pre][v[i]] != 1) return 0;
        pre = v[i];
    }
    return 1;
}
int isHamilt() {
    if (v[0] != v[kn-1]) return 0;
    vector<int> times(kn, 0);
    for (int i = 0; i < kn; i++)
        times[v[i]]++;
    for (int i = 1; i < kn; i++)
        if ((i == v[0] && times[i] != 2) || (i != v[0] && times[i] != 1)) return 0;
    return 1;
}
int main() {
    int m, k, a, b;
    scanf("%d %d", &n, &m);
    graph.resize(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &kn);
        v.resize(kn);
        for (int j = 0; j < kn; j++)
            scanf("%d", &v[j]);
        printf("%s\n", (kn == n + 1 && isConnected() && isHamilt()) ? "YES" : "NO");
    }
    return 0;
}