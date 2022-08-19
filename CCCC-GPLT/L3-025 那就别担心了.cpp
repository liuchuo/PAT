#include <bits/stdc++.h>
using namespace std;
int N, M, S1, S2, A, B, consistency, laneNum[502];
vector<int> Edge[502];
int dfs(int index) {
    if (laneNum[index] != 0) return laneNum[index];
    for (int Next : Edge[index]) {
        if (laneNum[Next] == 0) dfs(Next);
        laneNum[index] += laneNum[Next];
    }
    if (laneNum[index] == 0) consistency = 1;
    return laneNum[index];
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> S1 >> S2;
        Edge[S1].push_back(S2);
    }
    cin >> A >> B;
    laneNum[B] = 1;
    dfs(A);
    cout << laneNum[A] << ' ' << (consistency ? "No" : "Yes");
    return 0;
}